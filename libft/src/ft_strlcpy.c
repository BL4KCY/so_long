/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:10:55 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:10:55 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*p_src;

	p_src = (char *)src;
	while (*p_src && size > 1)
	{
		*dst++ = *p_src++;
		size--;
	}
	if (size)
		*dst = '\0';
	return (ft_strlen(src));
}
