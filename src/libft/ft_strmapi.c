/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:47:33 by wawong            #+#    #+#             */
/*   Updated: 2018/04/18 17:59:42 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (new != NULL)
	{
		i = 0;
		while (*s)
		{
			new[i] = f(i, *s);
			i++;
			s++;
		}
		new[i] = '\0';
	}
	return (new);
}
