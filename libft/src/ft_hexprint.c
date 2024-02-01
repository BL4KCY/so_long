/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:30:15 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/23 14:49:12 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexprint(unsigned int num, int c)
{
	char	*hex;
	char	buffer[21];
	short	index;
	size_t	p;

	p = 0;
	index = 0;
	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (!num)
		return (ft_putchar('0'));
	while (num)
	{
		buffer[index++] = hex[num % 16];
		num /= 16;
	}
	while (--index >= 0)
		p += ft_putchar(buffer[index]);
	return (p);
}
