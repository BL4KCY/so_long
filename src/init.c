/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:46:21 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/10 18:36:21 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	item_counter(t_list *map, int *item)
{
	int	x;

	while (map)
	{
		x = -1;
		while (((char *)map->content)[++x])
		{
			if (((char *)map->content)[x] == '0')
				item[0]++;
			if (((char *)map->content)[x] == '1')
				item[1]++;
			if (((char *)map->content)[x] == 'C')
				item[2]++;
			if (((char *)map->content)[x] == 'G')
				item[3]++;
		}
		map = map->next;
	}
}

void	allocate_coors(t_mlx *server)
{
	int	item[6];

	item_counter(server->map, item);
	set_null(server);
	server->items.empty.x = malloc(item[0] * sizeof(int));
	server->items.empty.y = malloc(item[0] * sizeof(int));
	server->items.wall.x = malloc(item[1] * sizeof(int));
	server->items.wall.y = malloc(item[1] * sizeof(int));
	server->items.door.x = malloc(sizeof(int));
	server->items.door.y = malloc(sizeof(int));
	server->items.food.x = malloc(item[2] * sizeof(int));
	server->items.food.y = malloc(item[2] * sizeof(int));
	server->items.player.x = malloc(sizeof(int));
	server->items.player.y = malloc(sizeof(int));
	server->items.enemy.x = malloc(item[3] * sizeof(int));
	server->items.enemy.y = malloc(item[3] * sizeof(int));
	if (!server->items.empty.x || !server->items.empty.y
		||!server->items.wall.x || !server->items.wall.y
		|| !server->items.door.x || !server->items.door.y
		|| !server->items.food.x || !server->items.food.y
		|| !server->items.player.x || !server->items.player.y
		|| !server->items.enemy.x || !server->items.enemy.y)
		ft_exit(server, MALLOC_ERROR);
}

void	init_game(t_mlx *server)
{
	int	x;
	int	y;

	allocate_coors(server);
	coordinate_init(server, server->map, 0, 0);
	server->height = ft_lstsize(server->map) * ADD;
	server->width = ft_strlen(server->map->content) * ADD;
	check_path(server);
	server->items.empty.img = mlx_xpm_file_to_image(server->mlx,
			server->items.empty.path, &x, &y);
	server->items.wall.img = mlx_xpm_file_to_image(server->mlx,
			server->items.wall.path, &x, &y);
	server->moves = false;
	server->lock = true;
	server->enemy_moved = false;
	server->lose = false;
	server->won = false;
	server->win = mlx_new_window(server->mlx, server->width,
			server->height, "so_long");
	if (!server->win)
		ft_exit(server, WIN_ERROR);
	update_wall(server);
	update_empty(server);
	ft_lstclear(&server->map, free);
}

void	coordinate_init(t_mlx *server, t_list *map, int x, int y)
{
	while (map)
	{
		x = -1;
		while (((char *)map->content)[++x])
		{
			if (((char *)map->content)[x] == 'P')
				player_init(&server->items.player, x * ADD, y * ADD);
			if (((char *)map->content)[x] == '0'
				|| ((char *)map->content)[x] == 'P')
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

void	player_init(t_coor *player, int x, int y)
{
	static int	i = 0;

	if (i == 0)
		ft_strlcpy(player->path, "textures/player/r/0.xpm", 100);
	player->x[i] = x;
	player->y[i] = y;
	player->len = (++i);
}
