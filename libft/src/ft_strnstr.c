/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:11:26 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:11:26 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (!l_len)
		return ((char *)big);
	if (!big && !len)
		return (NULL);
	while (*big && len > 0 && len >= l_len)
	{
		if (*big == *little && !ft_strncmp(little, big, l_len))
			return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}
