/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:46:21 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/04 19:05:56 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(mlx_t *server)
{

	coordinate_init(server);
	(*server).moves = 0;
	server->width = ft_strlen(server->map->content) * ADD;
	server->hight = ft_lstsize(server->map) * ADD;
}


void	coordinate_init(mlx_t *server)
{
	int		x;
	int		y;
	t_list	*map;

	y = 0;
	map = server->map;
	while (map)
	{
		x = -1;
		while (((char *)map->content)[++x])
		{
			if (((char *)map->content)[x] == 'P')
				player_init(&server->items.player, x * ADD, y * ADD);
			if (((char *)map->content)[x] != '1')
				empty_init(&server->items.empty, x * ADD, y * ADD);
			if (((char *)map->content)[x] == '1')
				wall_init(&server->items.wall, x * ADD, y * ADD);
		}
		map = map->next;
		y++;
	}
	printf("%d %d\n", server->items.player.len, server->items.empty.len);
}

void	player_init(coor_t *player, int x, int y)
{
	static int i = 0;
	if (i == 0)
		ft_strlcpy(player->path, "textures/player/r/0.xpm", 100);
	player->x[i] = x;
	player->y[i] = y;
	player->len = (++i);
}

void	empty_init(coor_t *empty, int x, int y)
{

	static int i = 0;
	printf("%d\n", i);
	if (i == 0)
		ft_strlcpy(empty->path, "textures/empty/empty.xpm", 100);
	empty->x[i] = x;
	empty->y[i] = y;
	empty->len = (++i);
}

void	wall_init(coor_t *wall, int x, int y)
{
	static int i = 0;
	if (i == 0)
		ft_strlcpy(wall->path, "textures/wall/wall.xpm", 100);
	wall->x[i] = x;
	wall->y[i] = y;
	wall->len = (++i);
}
