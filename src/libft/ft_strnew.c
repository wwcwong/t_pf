/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:56:56 by wawong            #+#    #+#             */
/*   Updated: 2018/04/18 18:01:59 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char				*new;
	unsigned int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		new[i++] = '\0';
	new[i] = '\0';
	return (new);
}
