/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:20:45 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/07 19:12:53 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(mlx_t *server)
{
	int	x;
	int	y;

	if ((*server).lock != true)
		(*server).items.door.path[14] = '1';
	server->items.player.img = mlx_xpm_file_to_image(server->mlx,
			server->items.player.path, &x, &y);
	server->items.enemy.img = mlx_xpm_file_to_image(server->mlx,
			server->items.enemy.path, &x, &y);
	server->items.door.img = mlx_xpm_file_to_image(server->mlx,
			server->items.door.path, &x, &y);
	server->items.food.img = mlx_xpm_file_to_image(server->mlx,
			server->items.food.path, &x, &y);
	animation(server);
	return (0);
}

void	animation(mlx_t *server)
{
	update_food(server);
	update_enemy(server);
	update_door(server);
	update_player(server);
	update_moves(server);
	images_slayer(server);
}

void	images_slayer(mlx_t *server)
{
	if (server->items.door.img)
		mlx_destroy_image(server->mlx, server->items.door.img);
	if (server->items.food.img)
		mlx_destroy_image(server->mlx, server->items.food.img);
	if (server->items.enemy.img)
		mlx_destroy_image(server->mlx, server->items.enemy.img);
	if (server->items.player.img)
		mlx_destroy_image(server->mlx, server->items.player.img);
	server->items.door.img = NULL;
	server->items.food.img = NULL;
	server->items.enemy.img = NULL;
	server->items.player.img = NULL;
}

void	delay(size_t ms)
{
	ms *= 48000000;
	while (ms--)
		;
}
