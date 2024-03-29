/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:52 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 10:00:29 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_fd(char	*path, char **line, size_t *len)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(1);
	}
	*line = get_next_line(fd);
	if (!*line)
	{
		ft_putendl_fd("Error\n: Empty file", STDERR_FILENO);
		exit(1);
	}
	*len = ft_strlen(*line) - 1;
	line[0][*len] = '\0';
	return (fd);
}

int	check_line(char *line, int len, bool first, bool last)
{
	int			i;
	static int	object[3];

	i = 0;
	while ((++i < len - 1) && (line[0] == '1' && line[len - 1] == '1'))
	{
		if (first || last)
			if (line[i] != '1')
				return (false);
		if (line[i] == 'P')
			object[0]++;
		else if (line[i] == 'E')
			object[1]++;
		else if (line[i] == 'C')
			object[2]++;
		else if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'G' && line[i] != '1')
			return (false);
	}
	if ((last && (object[0] != 1 || object[1] != 1 || object[2] == 0))
		|| (line[0] != '1' || line[len - 1] != '1'))
		return (false);
	if (last)
		return (object[2]);
	return (true);
}

void	map_parse(char *path, t_mlx *par)
{
	size_t	len;
	char	*line;
	char	*buff;

	par->map = NULL;
	par->fd = get_fd(path, &line, &len);
	while (line)
	{
		buff = get_next_line(par->fd);
		par->score = check_line(line, len, par->map == NULL, buff == NULL);
		ft_lstadd_back(&(par->map), ft_lstnew(line));
		if (len != ft_strlen(line) || par->score == 0)
		{
			ft_putendl_fd("Error\n: INAVALID MAP!!!", STDERR_FILENO);
			ft_lstclear(&(par->map), free);
			deallocate_gnl(buff, par->fd);
			exit(1);
		}
		line = ft_strtrim(buff, "\n");
		free(buff);
	}
	close(par->fd);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
	{
		if (map[y][x] == 'E')
		{
			map[y][x] = '1';
			return ;
		}
		else
			map[y][x] = 'P';
		flood_fill(map, x + 1, y);
		flood_fill(map, x - 1, y);
		flood_fill(map, x, y + 1);
		flood_fill(map, x, y - 1);
	}
	else
		return ;
}

void	deallocate_gnl(void *memory, int fd)
{
	while (memory)
	{
		free(memory);
		memory = get_next_line(fd);
	}
}
