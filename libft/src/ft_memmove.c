/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:09:05 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:09:05 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_reverse(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_byte	*dest_ptr;
	t_byte	*src_ptr;

	i = 0;
	dest_ptr = (t_byte *)dest;
	src_ptr = (t_byte *)src;
	while (i < n)
	{
		dest_ptr[n - i - 1] = src_ptr[n - i -1];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == dest || !n)
		return (dest);
	if ((t_byte *)dest >= (t_byte *)src)
		ft_memcpy_reverse(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
