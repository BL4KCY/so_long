/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:01:00 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/18 11:43:40 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		sizetotal;
	int		index;
	int		i;

	index = (-1);
	sizetotal = ft_strlen_get(s1) + ft_strlen_get(s2);
	buffer = malloc(sizeof(char) * (sizetotal + 1));
	if (!buffer)
		return (NULL);
	while (s1[++index])
		buffer[index] = s1[index];
	i = (-1);
	while (s2[++i])
		buffer[index++] = s2[i];
	buffer[sizetotal] = 0;
	return (buffer);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	index;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	index = 0;
	while (index < count * size)
		res[index++] = 0;
	return (res);
}

size_t	ft_strlen_get(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}
