/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:20:45 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/10 18:30:59 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_mlx *server)
{
	int	x;
	int	y;

	if ((*server).lock != true)
		(*server).items.door.path[14] = '1';
	if (server->lose)
	{
		gameover(server, LOSER);
		return (0);
	}
	if (server->won)
	{
		gameover(server, WINER);
		return (0);
	}
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

void	animation(t_mlx *server)
{
	static int	f1 = 600;
	static int	f2 = 0;

	if (f1++ == 600)
	{
		update_food(server);
		update_enemy(server);
		f1 = 0;
	}
	if (f2++ == 2000)
	{
		move_enemy(server);
		check_enemy(server);
		f2 = 0;
	}
	update_door(server);
	update_player(server);
	update_moves(server);
	images_slayer(server);
}

void	images_slayer(t_mlx *server)
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
