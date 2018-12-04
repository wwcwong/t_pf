/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:05:57 by wawong            #+#    #+#             */
/*   Updated: 2018/04/19 00:14:58 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*temp;
	void		*copy;

	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	temp->next = NULL;
	if (!content)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		if (!(copy = malloc(content_size)))
			return (NULL);
		temp->content = ft_memcpy(copy, content, content_size);
		temp->content_size = content_size;
	}
	return (temp);
}
