/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:30:18 by wawong            #+#    #+#             */
/*   Updated: 2018/04/17 03:14:31 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t start;

	i = 0;
	j = 0;
	start = 0;
	while (needle[j] != '\0')
		j++;
	if (j == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (needle[start] == haystack[i + start] && (i + start) < len
				&& haystack[i + start])
		{
			if (start == j - 1)
				return ((char*)haystack + i);
			start++;
		}
		start = 0;
		i++;
	}
	return (NULL);
}
