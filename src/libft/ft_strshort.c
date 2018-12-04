/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:49:43 by wawong            #+#    #+#             */
/*   Updated: 2018/12/02 17:49:47 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshort(char *s1, int len)
{
	char	*str;

	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(str, s1, len);
	free(s1);
	return (str);
}
