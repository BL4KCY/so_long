/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:10:08 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:10:08 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	p;

	p = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		p += ft_putchar(*s++);
	return (p);
}
