/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:14:56 by wawong            #+#    #+#             */
/*   Updated: 2018/11/27 23:26:37 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct	s_p
{
	va_list		args;
	char		*buf;
	int			width;
	int			plus;
	int			zero;
	int			pre;
	int			dot;
	int			space;
	int			sharp;
	int			mod;
	int			count;
	int			null;
}				t_p;

void			handle_flag(char *str, t_p *p, int m, int l);
void			handle_buffer_csp(t_p *p, char *s);
void			handle_buffer(t_p *p, char *s);
void			handle_pm(char *str, t_p *p, int m, int l);
void			handle_precision(char *str, t_p *p, int m, int l);
void			handle_width_sign(char *str, t_p *p, int len);
char			*str_append(char *s1, char *s2, int f1, int f2);
int				get_mod(char *str, t_p *p, int len);
intmax_t		handle_number(va_list arg, int len, int h);
uintmax_t		handle_unsiged_number(va_list arg, int len, int h);

#endif
