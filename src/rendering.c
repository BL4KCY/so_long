/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:20:45 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/04 19:09:16 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delay(size_t ms);

int	render_next_frame(mlx_t *server)
{
	static char	c = '0';

	delay(2);
	server->items.empty.img = mlx_xpm_file_to_image(server->mlx, server->items.empty.path, &server->width, &server->hight);
	server->items.player.img = mlx_xpm_file_to_image(server->mlx, server->items.player.path, &server->width, &server->hight);
	server->items.wall.img = mlx_xpm_file_to_image(server->mlx, server->items.wall.path, &server->width, &server->hight);
	animation(server);
	if (c <= '9')
		server->items.player.path[18] = c;
	else
		c = '0';
	c++;
	return (0);
}

void	update_empty(mlx_t *server)
{
	// printf("here %d\n", server->items.empty.len);
	for (int i = 0; i < server->items.empty.len; i++)
		mlx_put_image_to_window(server->mlx, server->win, server->items.empty.img, server->items.empty.x[i], server->items.empty.y[i]);
}

void	update_wall(mlx_t *server)
{
	for (int i = 0; i < server->items.wall.len; i++)
		mlx_put_image_to_window(server->mlx, server->win, server->items.wall.img, server->items.wall.x[i], server->items.wall.y[i]);
}

void animation(mlx_t *server)
{
	update_empty(server);
	update_wall(server);
	printf("here\n");
	update_player(server);
	update_moves(server);
	images_slayer(server);
}

void	images_slayer(mlx_t *server)
{
	// if (server->items.door.img)
	// 	mlx_destroy_image(server->mlx, server->items.door.img);
	if (server->items.empty.img)
		mlx_destroy_image(server->mlx, server->items.empty.img);
	// if (server->items.food.img)
	// 	mlx_destroy_image(server->mlx, server->items.food.img);
	// if (server->items.enemy.img)
	// 	mlx_destroy_image(server->mlx, server->items.enemy.img);
	if (server->items.wall.img)
		mlx_destroy_image(server->mlx, server->items.wall.img);
	if (server->items.player.img)
		mlx_destroy_image(server->mlx, server->items.player.img);
	server->items.door.img = NULL;
	server->items.empty.img = NULL;
	server->items.food.img = NULL;
	server->items.enemy.img = NULL;
	server->items.wall.img = NULL;
	server->items.player.img = NULL;
}

static void delay(size_t ms)
{
	ms *= 48000000;
	while (ms--)
		;
}
