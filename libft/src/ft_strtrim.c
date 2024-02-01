/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:11:31 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:11:31 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char_in_set(int c, const char *s)
{
	char	*set;

	set = (char *)s;
	while (*set && *set != c)
		set++;
	return (*set == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	start;
	char	*buffer;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && check_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && check_char_in_set(s1[end], set))
		end--;
	buffer = ft_calloc(sizeof(char), end - start + 2);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		buffer[i++] = s1[start++];
	buffer[i] = '\0';
	return (buffer);
}
