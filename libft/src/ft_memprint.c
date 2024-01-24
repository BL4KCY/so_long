/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:07:14 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/23 14:50:45 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_memprint(size_t num)
{
	char	buffer[21];
	char	*hex;
	int		p;
	short	index;

	p = 0;
	index = 0;
	hex = "0123456789abcdef";
	if (!num)
		return (ft_putstr("0x0"));
	p += ft_putstr("0x");
	while (num)
	{
		buffer[index++] = hex[num % 16];
		num /= 16;
	}
	while (--index >= 0)
		p += ft_putchar(buffer[index]);
	return (p);
}
