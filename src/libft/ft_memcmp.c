/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:40:23 by wawong            #+#    #+#             */
/*   Updated: 2018/04/19 12:52:30 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*((unsigned char*)s1) == (*(unsigned char*)s2))
		{
			s1++;
			s2++;
		}
		else
			return (*((unsigned char*)s1) - (*(unsigned char*)s2));
		n--;
	}
	return (0);
}
