/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prase_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:52 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/06 12:19:48 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_fd(char	*path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(strerror(ENOENT), STDERR_FILENO);
		exit(1);
	}
	return (fd);
}

int	check_line(char *line, int len, bool first, bool last)
{
	int	i;
	static int	object[3];

	i = 0;
	if (line[0] != '1' || line[len - 1] != '1') // check first and last char
		return (false);
	while (++i < len - 1)
	{
		if (first || last)
		{
			if (line[i] != '1')
				return (false);
		}
		else if (line[i] == 'P')
			object[0]++;
		else if (line[i] == 'E')
			object[1]++;
		else if (line[i] == 'C')
			object[2]++;
		else if (line[i] != '0' && line[i] != '1')
			return (false);
	}
	if (last)
	{
		if (object[0] != 1 || object[1] != 1 || (object[2] == 0 && last)) // check if there is only one P and E and at least one C
			return (false);
		return (object[2]);
	}
	return (true);
}

void	map_parse(char *path, mlx_t *par)
{
	int		fd;
	size_t	len;
	char	*line;
	char	*next_line;

	(*par).map = NULL;
	fd = get_fd(path);
	next_line = get_next_line(fd);
	line = ft_strtrim(next_line, "\n");
	free(next_line);
	len = ft_strlen(line);
	while (line)
	{
		next_line = get_next_line(fd);
		(*par).score = check_line(line, len, (*par).map == NULL, next_line == NULL);
		if (len != strlen(line) || par->score == 0)
		{
			ft_putendl_fd("Error\n", STDERR_FILENO);
			ft_lstclear(&((*par).map), free);
			exit(1);
		}
		ft_lstadd_back(&((*par).map), ft_lstnew(line));
		line = ft_strtrim(next_line, "\n");
		free(next_line);
	}
	close(fd);
}


