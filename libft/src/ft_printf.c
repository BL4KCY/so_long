/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:30:39 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/23 15:05:37 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	index;
	int		n_prt;
	int		old_index;

	n_prt = 0;
	index = 0;
	va_start(args, format);
	while (format[index])
	{
		old_index = index;
		if (format[index] == '%' && format[index + 1])
		{
			index++;
			n_prt += ft_print_format(format[index], args);
		}
		if (index == old_index && format[index] != '%')
			n_prt += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (n_prt);
}

int	ft_print_format(char format, va_list args)
{
	int	n_prt;

	n_prt = 0;
	if (format == '%')
		n_prt += ft_putchar(format);
	else if (format == 'c')
		n_prt += ft_putchar(va_arg(args, int));
	else if (format == 's')
		n_prt += ft_putstr(va_arg(args, char *));
	else if ((format == 'd' || format == 'i'))
		n_prt += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		n_prt += ft_putnbr(va_arg(args, unsigned int));
	else if ((format == 'x' || format == 'X'))
		n_prt += ft_hexprint(va_arg(args, unsigned int), format);
	else if (format == 'p')
		n_prt += ft_memprint((size_t)va_arg(args, void *));
	else
		n_prt += ft_putchar(format);
	return (n_prt);
}
