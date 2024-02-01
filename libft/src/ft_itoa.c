/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:04:56 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:04:56 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size(long n, int *sign)
{
	long	size;
	long	div;

	div = 1;
	size = 0;
	while (n / div != 0)
	{
		size++;
		div *= 10;
	}
	if (n < 0)
	{
		*sign = (-1);
		return (size + 1);
	}
	*sign = 1;
	if (!size)
		return (1);
	return (size);
}

static char	*ft_init(char *str, long n, int *sign)
{
	long	index;
	long	div;

	index = 0;
	div = 1;
	if (*sign == -1)
	{
		str[0] = '-';
		n *= (-1);
		index++;
	}
	while (div * 10 <= n)
		div *= 10;
	while (div)
	{
		str[index] = (n / div) + '0';
		n %= div;
		div /= 10;
		index++;
	}
	str[index] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	size;
	int		sign;
	char	*str;

	size = ft_get_size(n, &sign);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (ft_init(str, n, &sign));
}
