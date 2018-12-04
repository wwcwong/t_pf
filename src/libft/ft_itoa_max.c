/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:32:25 by wawong            #+#    #+#             */
/*   Updated: 2018/04/17 17:32:01 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char		*ft_itoa_max(intmax_t n)
{
	char		*str;
	size_t		size;
	size_t		flag;
	intmax_t	temp;

	if ((uintmax_t)n == -9223372036854775808ULL)
		return (ft_strdup("-9223372036854775808"));
	flag = (n < 0) ? 1 : 0;
	size = 0;
	temp = n;
	while (temp /= 10)
		size++;
	size = size + flag + 1;
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = (ft_abs(n % 10) + '0');
		size--;
		n /= 10;
	}
	return (str);
}
