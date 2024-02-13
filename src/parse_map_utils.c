/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:36:20 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/13 16:26:13 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_mlx *par)
{
	char	**map_cpy;

	if (par->height > MAX_HEIGHT || par->width > MAX_WIDTH)
	{
		ft_putendl_fd("Error\nMAP TOO BIG!!!", STDERR_FILENO);
		ft_exit(par, INVALID_MAP);
	}
	map_cpy = copy_map(par, par->map);
	map_cpy[par->items.player.y[0] / ADD][par->items.player.x[0] / ADD] = '0';
	flood_fill(map_cpy, par->items.player.x[0] / ADD,
		par->items.player.y[0] / ADD);
	if (is_valid_path(par, map_cpy))
	{
		ft_free2d(map_cpy);
		return ;
	}
	ft_free2d(map_cpy);
	ft_putendl_fd("Error\nINVALID PATH !!", STDERR_FILENO);
	ft_exit(par, INVALID_MAP);
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

bool	door_path(t_mlx *par, char **copy)
{
	int		x;
	int		y;

	x = par->items.door.x[0] / ADD;
	y = par->items.door.y[0] / ADD;
	if (copy[y][x + 1] == 'P' || copy[y][x - 1] == 'P'
		|| copy[y + 1][x] == 'P' || copy[y - 1][x] == 'P')
		return (true);
	return (false);
}

bool	is_valid_path(t_mlx *par, char **copy)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	if (copy[par->items.door.y[0] / ADD][par->items.door.x[0] / ADD] != '1')
		return (false);
	while (++i < par->items.food.len)
	{
		x = par->items.food.x[i] / ADD;
		y = par->items.food.y[i] / ADD;
		if (copy[y][x] == 'P')
			continue ;
		return (false);
	}
	return (true);
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