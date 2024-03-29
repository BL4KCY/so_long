/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:19:16 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 10:01:13 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_food(t_mlx *par)
{
	int	i;

	i = 0;
	while (i < (*par).items.food.len)
	{
		if ((*par).items.player.y[0] == (*par).items.food.y[i]
			&& (*par).items.player.x[0] == (*par).items.food.x[i])
		{
			(*par).items.food.x[i] = par->width;
			(*par).items.food.y[i] = par->height;
			(*par).score--;
			mlx_put_image_to_window(par->mlx, par->win, par->items.wall.img,
				(*par).items.food.x[i], (*par).items.food.y[i]);
		}
		i++;
	}
}

bool	check_wall(t_mlx *par, int add, bool is_x)
{
	int	i;

	i = 0;
	while (i < (*par).items.wall.len)
	{
		if (is_x)
		{
			if ((*par).items.player.y[0] == (*par).items.wall.y[i]
				&& ((*par).items.player.x[0] + add) == (*par).items.wall.x[i])
				return (false);
		}
		else
			if (((*par).items.player.y[0] + add) == (*par).items.wall.y[i]
				&& (*par).items.player.x[0] == (*par).items.wall.x[i])
				return (false);
		i++;
	}
	return (true);
}

bool	check_door(t_mlx *par, int add, bool is_x)
{
	if (is_x)
	{
		if (((*par).items.player.x[0] + add) == (*par).items.door.x[0]
			&& (*par).items.player.y[0] == (*par).items.door.y[0])
		{
			if (!(*par).lock)
				par->won = true;
			return (false);
		}
	}
	if (!is_x)
	{
		if (((*par).items.player.y[0] + add) == (*par).items.door.y[0]
			&& (*par).items.player.x[0] == (*par).items.door.x[0])
		{
			if (!(*par).lock)
				par->won = true;
			return (false);
		}
	}
	return (true);
}

void	check_enemy(t_mlx *par)
{
	int	i;

	i = 0;
	while (i < (*par).items.enemy.len)
	{
		if ((*par).items.player.y[0] == (*par).items.enemy.y[i]
			&& (*par).items.player.x[0] == (*par).items.enemy.x[i])
			par->lose = true;
		i++;
	}
}

void	update_player(t_mlx *param)
{
	static int	f2 = 300;
	static int	c = '0';

	if (f2++ == 300)
	{
		if (c++ <= '9')
			param->items.player.path[18] = c++;
		else
			c = '0';
		f2 = 0;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->items.player.img,
		param->items.player.x[0], param->items.player.y[0]);
}
