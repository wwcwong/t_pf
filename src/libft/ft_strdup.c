/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:45:42 by wawong            #+#    #+#             */
/*   Updated: 2018/04/16 21:55:38 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	str = (char*)malloc(sizeof(*str) * (j + 1));
	if (str == 0)
		return (0);
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
