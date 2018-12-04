/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:47:01 by wawong            #+#    #+#             */
/*   Updated: 2018/12/02 17:47:22 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_alloc(char *buf, char *str)
{
	int	len;

	if (str)
	{
		len = 0;
		while (str[len])
			len++;
		if (!(buf = ft_strnew(len)))
			return (NULL);
		len = -1;
		while (str[++len])
			buf[len] = str[len];
		buf[len] = str[len];
		return (buf);
	}
	else
		return (NULL);
}
