/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:14:45 by wawong            #+#    #+#             */
/*   Updated: 2018/04/16 23:45:46 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = dst;
	p2 = (char*)src;
	if (ft_strlen(p2) < len)
	{
		while (i++ < ft_strlen(p2))
			*(dst++) = *(src++);
		while (i++ <= len)
			*(dst++) = '\0';
	}
	else
	{
		while (i++ < len && src)
			*(dst++) = *(src++);
	}
	return (p1);
}
