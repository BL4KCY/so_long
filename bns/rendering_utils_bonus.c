/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:14:39 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 10:00:31 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_empty(t_mlx *server)
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

void	update_wall(t_mlx *server)
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

void	update_door(t_mlx *server)
{
	int		x;
	int		y;
	void	*img;

	x = server->items.door.x[0];
	y = server->items.door.y[0];
	img = server->items.door.img;
	mlx_put_image_to_window(server->mlx, server->win, img, x, y);
}

void	update_food(t_mlx *server)
{
	int			j;
	void		*img;
	int			x;
	int			y;
	static int	n;

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

void	update_enemy(t_mlx *server)
{
	static int	c = '0';
	int			j;

	if (c <= '4')
		server->items.enemy.path[15] = c++;
	else
		c = '0';
	j = -1;
	if (server->enemy_moved)
		mlx_put_image_to_window(server->mlx, server->win,
			server->items.empty.img, server->enemy_dir[0],
			server->enemy_dir[1]);
	server->enemy_moved = false;
	while (++j < server->items.enemy.len)
	{
		mlx_put_image_to_window(server->mlx, server->win,
			server->items.enemy.img, server->items.enemy.x[j],
			server->items.enemy.y[j]);
	}
}
