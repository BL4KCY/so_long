/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:14:39 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/07 19:15:57 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_empty(mlx_t *server)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	i = -1;
	while (i++ < server->items.empty.len)
	{
		x = server->items.empty.x[i];
		y = server->items.empty.y[i];
		img = server->items.empty.img;
		mlx_put_image_to_window(server->mlx, server->win, img, x, y);
	}
}

void	update_wall(mlx_t *server)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	i = -1;
	while (i++ < server->items.wall.len)
	{
		x = server->items.wall.x[i];
		y = server->items.wall.y[i];
		img = server->items.wall.img;
		mlx_put_image_to_window(server->mlx, server->win, img, x, y);
	}
}

void	update_door(mlx_t *server)
{
	int		x;
	int		y;
	void	*img;

	x = server->items.door.x[0];
	y = server->items.door.y[0];
	img = server->items.door.img;
	mlx_put_image_to_window(server->mlx, server->win, img, x, y);
}

void	update_food(mlx_t *server)
{
	int			j;
	void		*img;
	int			x;
	int			y;
	static int  n;

	img = server->items.food.img;
	if (n++ == 1)
	{
		server->items.food.path[14] = '1';
		n = 0;
	}
	else
		server->items.food.path[14] = '0';
	j = -1;
	while (++j < server->items.food.len)
	{
		x = server->items.food.x[j];
		y = server->items.food.y[j];
		if (server->items.food.x[j] == -1)
			mlx_put_image_to_window(server->mlx, server->win,
				server->items.wall.img, 0, 0);
		else
			mlx_put_image_to_window(server->mlx, server->win, img, x, y);
	}
}

void	update_enemy(mlx_t *server)
{
	static int	c = '0';
	int			j;


	if (c <= '4')
		server->items.enemy.path[19] = c++;
	else
		c = '0';
	j = -1;
	while (++j < server->items.enemy.len)
	{
		if (server->items.enemy.x[j] == server->items.player.x[0]
			&& server->items.enemy.y[j] == server->items.player.y[0])
			gameover(server);
		mlx_put_image_to_window(server->mlx, server->win,
			server->items.enemy.img, server->items.enemy.x[j],
			server->items.enemy.y[j]);
	}
}
