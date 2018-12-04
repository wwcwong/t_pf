/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:28:52 by wawong            #+#    #+#             */
/*   Updated: 2018/04/18 17:47:29 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
			new[i++] = f(*s);
			s++;
		}
		new[i] = '\0';
	}
	return (new);
}
