/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:18:51 by wawong            #+#    #+#             */
/*   Updated: 2018/12/03 20:18:59 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t		handle_number(va_list arg, int len, int h)
{
	intmax_t	val;

	if (len == 3)
		return (va_arg(arg, long long));
	else if (len == 4)
		return (va_arg(arg, long));
	else if (len == 5)
		return (va_arg(arg, intmax_t));
	else if (len == 6)
		return (va_arg(arg, size_t));
	val = (h) ? va_arg(arg, long) : va_arg(arg, int);
	if (!h)
	{
		if (len == 0)
			val = (int)val;
		else if (len == 1)
			val = (char)val;
		else if (len == 2)
			val = (short)val;
	}
	return (val);
}

uintmax_t		handle_unsiged_number(va_list arg, int len, int h)
{
	uintmax_t	val;

	if (len == 3)
		return (va_arg(arg, unsigned long long));
	else if (len == 4)
		return (va_arg(arg, unsigned long));
	else if (len == 5)
		return (va_arg(arg, uintmax_t));
	if (len == 6)
		return (va_arg(arg, size_t));
	val = (h) ? va_arg(arg, unsigned long) : va_arg(arg, unsigned int);
	if (!h)
	{
		if (len == 0)
			val = (unsigned int)val;
		else if (len == 1)
			val = (unsigned char)val;
		else if (len == 2)
			val = (unsigned short)val;
	}
	return (val);
}

char			*str_append(char *s1, char *s2, int f1, int f2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return ((void *)0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (f1)
		free(s1);
	if (f2)
		free(s2);
	return (str);
}

int				get_mod(char *str, t_p *p, int len)
{
	p->width = 0;
	p->sharp = 0;
	p->plus = 0;
	p->zero = 0;
	p->pre = -1;
	p->dot = 0;
	p->space = 0;
	while (*str && len-- > 0 && !(ft_strchr("hljzL", *str)))
		str++;
	if (ft_strncmp(str, "hh", 2) == 0)
		return (1);
	if (ft_strncmp(str, "h", 1) == 0)
		return (2);
	if (ft_strncmp(str, "ll", 2) == 0)
		return (3);
	if (ft_strncmp(str, "l", 1) == 0 || ft_strncmp(str, "L", 1) == 0)
		return (4);
	if (ft_strncmp(str, "j", 1) == 0)
		return (5);
	if (ft_strncmp(str, "z", 1) == 0)
		return (6);
	return (0);
}
