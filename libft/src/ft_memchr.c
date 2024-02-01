/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:08:27 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:08:27 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	t_byte	*s_ptr;

	i = 0;
	s_ptr = (t_byte *)s;
	while (i < n)
	{
		if (s_ptr[i] == c)
			return ((t_byte *)s + i);
		i++;
	}
	return (NULL);
}
