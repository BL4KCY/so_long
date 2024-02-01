/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:10:25 by melfersi          #+#    #+#             */
/*   Updated: 2023/11/01 10:10:25 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word);
}

static void	copy(const char *s, char *world, size_t start, size_t word_len)
{
	size_t	index;

	index = 0;
	while (index < word_len)
	{
		world[index] = s[start + index];
		index++;
	}
	world[index] = 0;
}

static void	set(size_t *a, size_t *b, size_t *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

static int	split_string(char **sout, size_t word_cout, const char *s, char c)
{
	size_t	index;
	size_t	i;
	size_t	word_len;

	set(&index, &i, &word_len);
	while (index < word_cout)
	{
		while (s[i] == c)
			i++;
		while (s[i++] != c)
			word_len++;
		sout[index] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (sout[index] == NULL)
		{
			while (0 < index)
				free(sout[--index]);
			return (0);
		}
		copy(s, sout[index++], --i - word_len, word_len);
		word_len = 0;
	}
	sout[index] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**str_out;
	int		status;

	if (s == NULL)
		return (NULL);
	word_count = word_counter(s, c);
	str_out = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (str_out == NULL)
		return (NULL);
	status = split_string(str_out, word_count, s, c);
	if (!status)
	{
		free(str_out);
		return (NULL);
	}
	return (str_out);
}
