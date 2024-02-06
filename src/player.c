/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:19:16 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/06 10:58:04 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	w_key(mlx_t *par)
{
	int i = 0;

	(*par).items.player.path[16] = 'u';
	while (i < (*par).items.wall.len)
	{
		if (((*par).items.player.y[0] - ADD) == (*par).items.wall.y[i] && (*par).items.player.x[0] == (*par).items.wall.x[i])
			return;
		i++;
	}
	if (((*par).items.player.y[0] - ADD) == (*par).items.door.y[0] &&
		(*par).items.player.x[0] == (*par).items.door.x[0] && (*par).items.door.len == 0)
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img, (*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.y[0] -= ADD;
}

void	a_key(mlx_t *par)
{
	int i = 0;

	(*par).items.player.path[16] = 'l';
	while (i < (*par).items.wall.len)
	{
		if ((*par).items.player.y[0] == (*par).items.wall.y[i] && ((*par).items.player.x[0] - ADD) == (*par).items.wall.x[i])
			return;
		i++;
	}
	if ((*par).items.player.y[0] == (*par).items.door.y[0] &&
		((*par).items.player.x[0] - ADD) == (*par).items.door.x[0] && (*par).items.door.len == 0)
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img, (*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.x[0] -= ADD;
}

void	d_key(mlx_t *par)
{
	int i = 0;

	(*par).items.player.path[16] = 'r';
	while (i < (*par).items.wall.len)
	{
		if ((*par).items.player.y[0] == (*par).items.wall.y[i] && ((*par).items.player.x[0] + ADD) == (*par).items.wall.x[i])
			return;
		i++;
	}
	if ((*par).items.player.y[0] == (*par).items.door.y[0] &&
		((*par).items.player.x[0] + ADD) == (*par).items.door.x[0] && (*par).items.door.len == 0)
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img, (*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.x[0] += ADD;
}

void	s_key(mlx_t *par)
{
	int i = 0;

	(*par).items.player.path[16] = 'd';
	while (i < (*par).items.wall.len)
	{
		if (((*par).items.player.y[0] + ADD) == (*par).items.wall.y[i] && (*par).items.player.x[0] == (*par).items.wall.x[i])
			return;
		i++;
	}
	if (((*par).items.player.y[0] + ADD) == (*par).items.door.y[0] &&
		(*par).items.player.x[0] == (*par).items.door.x[0] && (*par).items.door.len == 0)
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img, (*par).items.player.x[0], (*par).items.player.y[0]);
	(*par).items.player.y[0] += ADD;
}

void move_player(int keycode, mlx_t *par)
{
	if (keycode == W)
		w_key(par);
	else if (keycode == A)
		a_key(par);
	else if (keycode == D)
		d_key(par);
	else if (keycode == S)
		s_key(par);
}

void update_player(mlx_t *param)
{
	static int c = '0';

	// delay(4);
	if (c <= '9')
		param->items.player.path[18] = c++;
	else
		c = '0';
	mlx_put_image_to_window(param->mlx, param->win, param->items.player.img, param->items.player.x[0], param->items.player.y[0]);
}

