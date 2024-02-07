/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:19:16 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/07 13:50:02 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_food(mlx_t *par)
{
	int	i;

	i = 0;
	while (i < (*par).items.food.len)
	{
		if ((*par).items.player.y[0] == (*par).items.food.y[i]
			&& (*par).items.player.x[0] == (*par).items.food.x[i])
		{
			(*par).items.food.x[i] = par->width;
			(*par).items.food.y[i] = par->hight;
			(*par).score--;
			mlx_put_image_to_window(par->mlx, par->win, par->items.wall.img,
				(*par).items.food.x[i], (*par).items.food.y[i]);
		}
		i++;
	}
}

bool	check_wall(mlx_t *par, int add, bool is_x)
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

bool	check_door(mlx_t *par, int add, bool is_x)
{
	if (is_x)
		if (((*par).items.player.x[0] + add) == (*par).items.door.x[0]
			&& (*par).items.player.y[0] == (*par).items.door.y[0])
		{
			if ((*par).lock)
				return (false);
			else
				ft_exit(par);
		}
	if (!is_x)
		if (((*par).items.player.y[0] + add) == (*par).items.door.y[0]
			&& (*par).items.player.x[0] == (*par).items.door.x[0])
		{
			if ((*par).lock)
				return (false);
			else
				ft_exit(par);
		}
	return (true);
}


void	w_key(mlx_t *par)
{
	(*par).items.player.path[16] = 'u';
	if (!check_wall(par, -ADD, false) || !check_door(par, -ADD, false))
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img,\
		(*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.y[0] -= ADD;
	(*par).moves++;
	check_food(par);
}

void	a_key(mlx_t *par)
{
	(*par).items.player.path[16] = 'l';
	if (!check_wall(par, -ADD, true) || !check_door(par, -ADD, true))
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img,\
		(*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.x[0] -= ADD;
	(*par).moves++;
	check_food(par);
}

void	d_key(mlx_t *par)
{
	(*par).items.player.path[16] = 'r';
	if (!check_wall(par, ADD, true) || !check_door(par, ADD, true))
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img,\
		(*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.x[0] += ADD;
	(*par).moves++;
	check_food(par);
}

void	s_key(mlx_t *par)
{
	(*par).items.player.path[16] = 'd';
	if (!check_wall(par, ADD, false) || !check_door(par, ADD, false))
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img,
		(*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.y[0] += ADD;
	(*par).moves++;
	check_food(par);
}

void move_player(int keycode, mlx_t *par)
{
	if (keycode == W)
		w_key(par);
	if (keycode == A)
		a_key(par);
	if (keycode == D)
		d_key(par);
	if (keycode == S)
		s_key(par);
	if ((*par).score == 0)
		(*par).lock = false;
}

void update_player(mlx_t *param)
{
	static int c = '0';
	static int i = 0;
	int limit = (INT_MAX / 40) / (param->hight * param->width);

	if (i < limit)
	{
		if (i == limit / 2)
		{
			if (c <= '9')
				param->items.player.path[18] = c++;
			else
				c = '0';
		}
		i++;
	}
	else
		i = 0;
	mlx_put_image_to_window(param->mlx, param->win, param->items.player.img, param->items.player.x[0], param->items.player.y[0]);
}

