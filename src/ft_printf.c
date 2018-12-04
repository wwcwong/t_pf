/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 21:37:17 by wawong            #+#    #+#             */
/*   Updated: 2018/11/29 06:46:06 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include "libft.h"

void			print_str(char *str, t_p *p)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(str);
	while (p->width > (l + p->null))
	{
		(p->zero && !p->dot) ? ft_putchar('0') : ft_putchar(' ');
		p->count++;
		p->width--;
	}
	if (str[i] || p->null)
		while (str[i] || p->null)
		{
			(p->null) && (p->null = 0);
			ft_putchar(str[i++]);
			p->count++;
		}
	if (p->width < 0)
		while (p->width < (l * -1) - p->null)
		{
			ft_putchar(' ');
			p->count++;
			p->width++;
		}
}

void			handle_buffer_csp(t_p *p, char *s)
{
	if (ft_strchr("cC", *s))
	{
		p->buf = ft_chartostr(va_arg(p->args, int));
		if (p->buf[0] == 0)
			p->null = 1;
	}
	else if (ft_strchr("sS", *s))
	{
		p->buf = ft_alloc(p->buf, va_arg(p->args, char*));
		if (!(p->buf))
			p->buf = ft_strdup("(null)");
	}
	else if (*s == 'p')
	{
		p->buf = ft_itoa_base((long)(va_arg(p->args, void*)), 16, 0);
		p->buf = str_append("0x", p->buf, 0, 1);
	}
	else
		p->buf = ft_strdup("%");
}

int				handle_spec(t_p *p, char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr("sSdDioOuUxXcCfp%", str[i]))
		i++;
	if (!str[i])
		return (i - 1);
	p->mod = get_mod(str, p, i);
	handle_buffer(p, &str[i]);
	handle_width_sign(str, p, i);
	handle_precision(str, p, i, ft_strlen(p->buf));
	handle_pm(str, p, i, ft_strlen(p->buf));
	handle_flag(str, p, i, ft_strlen(p->buf));
	if (p->space && !p->plus && p->buf[0] != '-' && ft_strchr("dDif", str[i]))
		p->buf = str_append(" ", p->buf, 0, 1);
	print_str(p->buf, p);
	(p->buf) ? free(p->buf) : 0;
	return (i);
}

int				ft_printf(const char *format, ...)
{
	t_p	*p;
	int	tmp;

	if (!(p = (t_p *)ft_memalloc(sizeof(t_p) * 1)))
		return (0);
	p->count = 0;
	p->null = 0;
	va_start(p->args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			format += handle_spec(p, (char *)(format + 1)) + 1;
		else if (!(*format == '%' && *(format + 1) == '\0'))
		{
			ft_putchar(*format);
			p->count++;
		}
		format++;
	}
	va_end(p->args);
	tmp = p->count;
	free(p);
	return (tmp);
}
