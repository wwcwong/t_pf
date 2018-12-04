/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:07:51 by wawong            #+#    #+#             */
/*   Updated: 2018/04/17 00:29:51 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int start;

	i = 0;
	j = 0;
	start = 0;
	while (needle[j] != '\0')
		j++;
	if (j == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (needle[start] == haystack[i + start])
		{
			if (start == j - 1)
				return ((char*)haystack + i);
			start++;
		}
		start = 0;
		i++;
	}
	return (0);
}
