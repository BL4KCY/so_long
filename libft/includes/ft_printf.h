/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:31:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 10:54:04 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_memprint(size_t num);
int	ft_hexprint(unsigned int num, int c);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(ssize_t n);
int	ft_print_format(char format, va_list args);
int	ft_puts(char *s);

#endif
