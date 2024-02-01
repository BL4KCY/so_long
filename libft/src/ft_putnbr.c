/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:09:57 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:09:57 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(ssize_t n)
{
	ssize_t	div;
	int		p;

	p = 0;
	div = 1;
	if (n < 0)
	{
		p += ft_putchar('-');
		n *= (-1);
	}
	while (div * 10 <= n)
		div *= 10;
	while (div)
	{
		p += ft_putchar((n / div) + '0');
		n %= div;
		div /= 10;
	}
	return (p);
}
