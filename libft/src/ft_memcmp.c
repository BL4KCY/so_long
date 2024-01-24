/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:08:48 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:08:48 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_byte	*s1_ptr;
	t_byte	*s2_ptr;

	if (!n || s1 == s2)
		return (0);
	s1_ptr = (t_byte *)s1;
	s2_ptr = (t_byte *)s2;
	while (n > 0)
	{
		if (*s1_ptr++ != *s2_ptr++)
			return (*--s1_ptr - *--s2_ptr);
		n--;
	}
	return (0);
}
