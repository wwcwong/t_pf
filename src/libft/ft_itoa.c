/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wawong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:32:25 by wawong            #+#    #+#             */
/*   Updated: 2018/04/17 17:32:01 by wawong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		flag;
	int		temp;

	flag = 0;
	size = 0;
	if (n < 0)
		flag = 1;
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
