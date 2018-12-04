/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:17:16 by wawong            #+#    #+#             */
/*   Updated: 2018/12/03 20:17:33 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			handle_width_sign(char *str, t_p *p, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len && p->width == 0)
	{
		if (ft_strchr("123456789", str[i]) && str[i - 1] != '.')
			p->width = ft_atoi(&str[i]);
		i++;
	}
	i = 0;
	while (str[i] && i < len)
	{
		(str[i] == '-') && (p->width *= -1);
		(str[i] == '#') && (p->sharp = 1);
		(str[i] == '+') && (p->plus = 1);
		(str[i] == '.') && (p->dot = 1);
		(str[i] == ' ') && (p->space = 1);
		(!ft_strchr("123456789.", str[i - 1]) && str[i] == '0')
			&& (p->zero = 1);
		if (str[i] == '.' && ft_strchr("0123456789", str[i + 1]))
			(p->pre = ft_atoi(&str[i + 1]));
		(str[i] == '.' && !ft_strchr("0123456789", str[i + 1]) && p->pre == -1)
			&& (p->pre = 0);
		i++;
	}
}

void			handle_precision(char *str, t_p *p, int m, int l)
{
	if (ft_strchr("uUidDfxXoO", str[m]))
	{
		if (p->pre == 0 && p->buf[0] == '0')
			p->buf = ft_strdup("");
		else if (p->pre > l || (p->pre >= l && p->buf[0] == '-'))
		{
			if (p->buf[0] != '-')
				p->buf = str_append(strset('0', (p->pre - l) - 1),
									p->buf, 1, 1);
			else
			{
				p->buf = ft_strsub(p->buf, 1, l - 1);
				p->buf = str_append(strset('0', p->pre - l), p->buf, 1, 1);
				p->buf = str_append("-", p->buf, 0, 1);
			}
		}
		else if (p->width >= l && p->buf[0] == '-' && p->zero)
		{
			p->buf = ft_strsub(p->buf, 1, l - 1);
			p->buf = str_append(strset('0', (p->width - l) - 1), p->buf, 1, 1);
			p->buf = str_append("-", p->buf, 0, 1);
		}
	}
	else if (ft_strchr("sS", str[m]) && (p->pre < l && p->pre != -1))
		p->buf = ft_strshort(p->buf, p->pre);
}

void			handle_pm(char *str, t_p *p, int m, int l)
{
	if (p->plus == 1)
	{
		if (p->buf[0] != '-' && ft_strchr("dDif", str[m]))
		{
			if (p->zero == 1 && p->width > 0)
			{
				p->buf = str_append(strset('0', (p->width - l) - 2),
									p->buf, 1, 1);
				p->width = 0;
			}
			p->buf = str_append("+", p->buf, 0, 1);
		}
	}
}

void			handle_flag(char *str, t_p *p, int m, int l)
{
	if (p->sharp == 1)
	{
		if (p->buf[0] != '0' && p->buf[0] && (str[m] == 'x' || str[m] == 'X'))
		{
			if (p->zero == 1 && p->width > 0)
			{
				p->buf = str_append(strset('0', (p->width - l) - 3),
									p->buf, 1, 1);
				p->width = 0;
			}
			if (str[m] == 'x')
				p->buf = str_append("0x", p->buf, 0, 1);
			else if (str[m] == 'X')
				p->buf = str_append("0X", p->buf, 0, 1);
		}
		else if ((str[m] == 'o' || str[m] == 'O') && p->buf[0] != '0')
			p->buf = str_append("0", p->buf, 0, 1);
	}
}

void			handle_buffer(t_p *p, char *s)
{
	intmax_t	value;
	uintmax_t	u_value;

	if (ft_strchr("cCsSp%", *s))
		handle_buffer_csp(p, s);
	else
	{
		if (ft_strchr("dDif", *s))
		{
			value = handle_number(p->args, p->mod, (*s == 'D'));
			p->buf = ft_itoa_max(value);
		}
		else
		{
			u_value = handle_unsiged_number(p->args, p->mod, (*s == 'U'));
			if (ft_strchr("oO", *s))
				p->buf = ft_itoa_base(u_value, 8, 0);
			else if (ft_strchr("uU", *s))
				p->buf = ft_itoa_base(u_value, 10, 0);
			else if (ft_strchr("xX", *s))
				p->buf = ft_itoa_base(u_value, 16, (*s == 'X'));
		}
	}
}
