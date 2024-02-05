/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prase_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:52 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/05 10:24:06 by melfersi         ###   ########.fr       */
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

bool	check_line(char *line, int len, bool first, bool last)
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
		if (object[0] != 1 || object[1] != 1 || (object[2] == 0 && last)) // check if there is only one P and E and at least one C
			return (false);
	return (true);
}

t_list	*map_parse(char *path)
{
	int		fd;
	size_t	len;
	char	*line;
	char	*next_line;
	t_list	*map;

	map = NULL;
	fd = get_fd(path);
	next_line = get_next_line(fd);
	line = ft_strtrim(next_line, "\n");
	free(next_line);
	len = ft_strlen(line);
	while (line)
	{
		next_line = get_next_line(fd);
		if (len != strlen(line) || check_line(line, len, map == NULL, next_line == NULL) == 0)
		{
			ft_putendl_fd("Error\n", STDERR_FILENO);
			ft_lstclear(&map, free);
			exit(1);
		}
		ft_lstadd_back(&map, ft_lstnew(line));
		line = ft_strtrim(next_line, "\n");
		free(next_line);
	}
	close(fd);
	return (map);
}


