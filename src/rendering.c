/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:20:45 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/07 12:02:57 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	render_next_frame(mlx_t *server)
{
	int x, y;
	if ((*server).lock != true)
		(*server).items.door.path[14] = '1';
	server->items.player.img = mlx_xpm_file_to_image(server->mlx, server->items.player.path, &x, &y);
	server->items.enemy.img = mlx_xpm_file_to_image(server->mlx, server->items.enemy.path, &x, &y);
	server->items.door.img = mlx_xpm_file_to_image(server->mlx, server->items.door.path, &x, &y);
	server->items.food.img = mlx_xpm_file_to_image(server->mlx, server->items.food.path, &x, &y);
	animation(server);
	// printf("score  = %d\n", server->score);
	return (0);
}

void	update_empty(mlx_t *server)
{
	for (int i = 0; i < server->items.empty.len; i++)
		mlx_put_image_to_window(server->mlx, server->win, server->items.empty.img, server->items.empty.x[i], server->items.empty.y[i]);
}

void	update_wall(mlx_t *server)
{
	for (int i = 0; i < server->items.wall.len; i++)
		mlx_put_image_to_window(server->mlx, server->win, server->items.wall.img, server->items.wall.x[i], server->items.wall.y[i]);
}

void	update_door(mlx_t *server)
{
	mlx_put_image_to_window(server->mlx, server->win, server->items.door.img, server->items.door.x[0], server->items.door.y[0]);
}

void	update_food(mlx_t *server)
{
	static int i = 0;
	int limit = (INT_MAX / 3) / (server->hight * server->width);

	if (i <= limit)
	{
		if (i == limit / 2)
			server->items.food.path[14] = '1';
		if (i == 0)
			server->items.food.path[14] = '0';
		i++;
	}
	else
		i = 0;
	for (int i = 0; i < server->items.food.len; i++)
		if (server->items.food.x[i] != -1)
			mlx_put_image_to_window(server->mlx, server->win, server->items.food.img, server->items.food.x[i], server->items.food.y[i]);
		else
		{
			mlx_put_image_to_window(server->mlx, server->win, server->items.wall.img, 0, 0);
		}
}

void	update_enemy(mlx_t *server)
{
	static int i = 0;
	static int c = '0';

	int limit = (INT_MAX / 20) / (server->hight * server->width);

	if (++i < limit)
	{
		if (i == limit / 2)
		{
			if (c <= '4')
				server->items.enemy.path[19] = c++;
			else
				c = '0';
		}
	}
	else
		i = -1;
	for (int i = 0; i < server->items.enemy.len; i++)
	{
		if (server->items.enemy.x[i] == server->items.player.x[0] && server->items.enemy.y[i] == server->items.player.y[0])
			gameover(server);
		mlx_put_image_to_window(server->mlx, server->win, server->items.enemy.img, server->items.enemy.x[i], server->items.enemy.y[i]);
	}
}

void animation(mlx_t *server)
{
	update_food(server);
	update_door(server);
	update_player(server);
	update_moves(server);
	update_enemy(server);
	images_slayer(server);
}

void	images_slayer(mlx_t *server)
{
	if (server->items.door.img)
		mlx_destroy_image(server->mlx, server->items.door.img);
	// if (server->items.empty.img)
	// 	mlx_destroy_image(server->mlx, server->items.empty.img);
	if (server->items.food.img)
		mlx_destroy_image(server->mlx, server->items.food.img);
	if (server->items.enemy.img)
		mlx_destroy_image(server->mlx, server->items.enemy.img);
	// if (server->items.wall.img)
	// 	mlx_destroy_image(server->mlx, server->items.wall.img);
	if (server->items.player.img)
		mlx_destroy_image(server->mlx, server->items.player.img);
	server->items.door.img = NULL;
	server->items.food.img = NULL;
	server->items.enemy.img = NULL;
	// server->items.empty.img = NULL;
	// server->items.wall.img = NULL;
	server->items.player.img = NULL;
}

void delay(size_t ms)
{
	ms *= 48000000;
	while (ms--)
		;
}
