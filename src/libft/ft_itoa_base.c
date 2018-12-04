/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:31:22 by wawong            #+#    #+#             */
/*   Updated: 2018/12/03 20:32:41 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(uintmax_t value, int base, int upper)
{
	char		*s;
	uintmax_t	n;
	int			i;

	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = ft_strnew(i);
	n = value;
	while (i--)
	{
		if (upper == 1)
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		else
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}
