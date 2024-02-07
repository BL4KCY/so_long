/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:46:21 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/07 13:37:35 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(mlx_t *server)
{
	int	x;
	int	y;

	coordinate_init(server, server->map, 0, 0);
	server->items.empty.img = mlx_xpm_file_to_image(server->mlx,
			server->items.empty.path, &x, &y);
	server->items.wall.img = mlx_xpm_file_to_image(server->mlx,
			server->items.wall.path, &x, &y);
	(*server).moves = 0;
	(*server).lock = 1;
	server->width = ft_strlen(server->map->content) * ADD;
	server->hight = ft_lstsize(server->map) * ADD;
}

void	coordinate_init(mlx_t *server, t_list *map, int x, int y)
{
	while (map)
	{
		x = -1;
		while (((char *)map->content)[++x])
		{
			if (((char *)map->content)[x] == 'P')
				player_init(&server->items.player, x * ADD, y * ADD);
			if (((char *)map->content)[x] == '0' ||
				((char *)map->content)[x] == 'P')
				empty_init(&server->items.empty, x * ADD, y * ADD);
			if (((char *)map->content)[x] == '1')
				wall_init(&server->items.wall, x * ADD, y * ADD);
			if (((char *)map->content)[x] == 'E')
				door_init(&server->items.door, x * ADD, y * ADD);
			if (((char *)map->content)[x] == 'C')
				food_init(&server->items.food, x * ADD, y * ADD);
			if (((char *)map->content)[x] == 'G')
				enemy_init(&server->items.enemy, x * ADD, y * ADD);
		}
		map = map->next;
		y++;
	}
}

void	player_init(coor_t *player, int x, int y)
{
	static int	i = 0;

	if (i == 0)
		ft_strlcpy(player->path, "textures/player/r/0.xpm", 100);
	player->x[i] = x;
	player->y[i] = y;
	player->len = (++i);
}
