/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prase_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:52 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/10 19:11:51 by melfersi         ###   ########.fr       */
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
	if (line[0] != '1' || line[len - 1] != '1')
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
		else if (line[i] != '0' && line[i] != '1' && line[i] != 'G')
			return (false);
	}
	if (last)
	{
		if (object[0] != 1 || object[1] != 1 || (object[2] == 0 && last))
			return (false);
		return (object[2]);
	}
	return (true);
}

void	map_parse(char *path, t_mlx *par)
{
	int		fd;
	size_t	len;
	char	*line;
	char	*next_line;

	par->map = NULL;
	fd = get_fd(path);
	next_line = get_next_line(fd);
	line = ft_strtrim(next_line, "\n");
	free(next_line);
	len = ft_strlen(line);
	while (line)
	{
		next_line = get_next_line(fd);
		par->score = check_line(line, len, par->map == NULL, next_line == NULL);
		if (len != strlen(line) || par->score == 0)
		{
			ft_putendl_fd("Error\nINAVALID MAP!!!", STDERR_FILENO);
			ft_lstclear(&(par->map), free);
			exit(1);
		}
		ft_lstadd_back(&(par->map), ft_lstnew(line));
		line = ft_strtrim(next_line, "\n");
		free(next_line);
	}
}

void	flood_fill(t_point	p, char **map, int h, int w, t_mlx *par)
{
	t_point	*stack;
	int		top;

	if (p.x < 0 || p.x >= w || p.y < 0 || p.y >= h)
		return ;
	stack = malloc(sizeof(t_point) * (h * w));
	if (!stack)
		ft_exit(par, MALLOC_ERROR);
	top = 0;
	stack[top++] = p;
	while (top)
	{
		printf("top = %d\n", top);
		p = stack[--top];
		if (p.x < 0 || p.x >= w || p.y < 0 || p.y >= h)
			continue ;
		if (map[p.y][p.x] == '0' || map[p.y][p.x] == 'C')
		{
			if (map[p.y][p.x] == '0')
				map[p.y][p.x] = 'P';
			stack[top++] = (t_point){p.x + 1, p.y};
			stack[top++] = (t_point){p.x - 1, p.y};
			stack[top++] = (t_point){p.x, p.y + 1};
			stack[top++] = (t_point){p.x, p.y - 1};
		}
	}
	free(stack);
}

bool	food_path(t_mlx *par, char **copy)
{
	int		x;
	int		y;

	for (int i = 0; i < par->items.food.len ;i++)
	{
		x = par->items.food.x[i] / ADD;
		y = par->items.food.y[i] / ADD;
		if (copy[y][x+1] == 'P' || copy[y][x-1] == 'P'
		|| copy[y+1][x] == 'P' || copy[y-1][x] == 'P')
			continue;
		return (false);
	}
	return (true);
}

bool	door_path(t_mlx *par, char **copy)
{
	int		x;
	int		y;

	x = par->items.door.x[0] / ADD;
	y = par->items.door.y[0] / ADD;
	if (copy[y][x+1] == 'P' || copy[y][x-1] == 'P'
		|| copy[y+1][x] == 'P' || copy[y-1][x] == 'P')
		return (true);
	return (false);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putendl_fd(map[i], STDOUT_FILENO);
		i++;
	}
}

char	**copy_map(t_mlx *par, t_list *map)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (par->height / ADD + 1));
	if (!copy)
		ft_exit(par, MALLOC_ERROR);
	while (map)
	{
		copy[i++] = ft_strdup(map->content);
		map = map->next;
	}
	copy[i] = NULL;
	return (copy);
}
void	ft_free2d(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_path(t_mlx *par)
{
	char	**map_cpy;

	map_cpy = copy_map(par, par->map);
	ft_lstclear(&par->map, free);
	map_cpy[par->items.player.y[0] / ADD][par->items.player.x[0] / ADD] = '0';
	flood_fill((t_point){par->items.player.x[0] / ADD, par->items.player.y[0] / ADD},
		map_cpy, par->height / ADD, par->width / ADD, par);
	printf("check_path\n");
	print_map(map_cpy);
	if (food_path(par, map_cpy) && door_path(par, map_cpy))
	{
		ft_free2d(map_cpy);
		return ;
	}
	ft_free2d(map_cpy);
	ft_putendl_fd("Error\nINVALID PATH !!", STDERR_FILENO);
	exit(1);
}
