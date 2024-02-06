/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:20:45 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/06 17:33:54 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	render_next_frame(mlx_t *server)
{
	int x, y;
	delay(2);
	if ((*server).lock != true)
		(*server).items.door.path[14] = '1';
	server->items.player.img = mlx_xpm_file_to_image(server->mlx, server->items.player.path, &x, &y);
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
	static int c = 0;

	if (c <= 40)
	{
		if (c == 20)
			server->items.food.path[14] = '1';
		if (c == 0)
			server->items.food.path[14] = '0';
		c++;
	}
	else
		c = 0;
	for (int i = 0; i < server->items.food.len; i++)
		if (server->items.food.x[i] != -1)
			mlx_put_image_to_window(server->mlx, server->win, server->items.food.img, server->items.food.x[i], server->items.food.y[i]);
}

void	update_enemy(mlx_t *server)
{
	static int c = '0';

	if (c <= '7')
		server->items.enemy.path[17] = c++;
	else
		c = '0';
	for (int i = 0; i < server->items.enemy.len; i++)
		mlx_put_image_to_window(server->mlx, server->win, server->items.enemy.img, server->items.enemy.x[i], server->items.enemy.y[i]);
}

void animation(mlx_t *server)
{
	// update_empty(server);
	update_food(server);
	update_door(server);
	update_player(server);
	update_moves(server);
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
	// if (server->items.enemy.img)
	// 	mlx_destroy_image(server->mlx, server->items.enemy.img);
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
