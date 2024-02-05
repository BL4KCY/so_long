/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:19:16 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/05 16:43:42 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	w_key(items_t *items)
{
	int i = 0;

	(*items).player.path[16] = 'u';
	while (i < (*items).wall.len)
	{
		if (((*items).player.y[0] - ADD) == (*items).wall.y[i] && (*items).player.x[0] == (*items).wall.x[i])
			return;
		i++;
	}
	if (((*items).player.y[0] - ADD) == (*items).door.y[0] &&
		(*items).player.x[0] == (*items).door.x[0] && (*items).door.len == 0)
		return ;
	(*items).player.y[0] -= ADD;
}

void	a_key(items_t *items)
{
	int i = 0;

	(*items).player.path[16] = 'l';
	while (i < (*items).wall.len)
	{
		if ((*items).player.y[0] == (*items).wall.y[i] && ((*items).player.x[0] - ADD) == (*items).wall.x[i])
			return;
		i++;
	}
	if ((*items).player.y[0] == (*items).door.y[0] &&
		((*items).player.x[0] - ADD) == (*items).door.x[0] && (*items).door.len == 0)
		return ;
	(*items).player.x[0] -= ADD;
}

void	d_key(items_t *items)
{
	int i = 0;

	(*items).player.path[16] = 'r';
	while (i < (*items).wall.len)
	{
		if ((*items).player.y[0] == (*items).wall.y[i] && ((*items).player.x[0] + ADD) == (*items).wall.x[i])
			return;
		i++;
	}
	if ((*items).player.y[0] == (*items).door.y[0] &&
		((*items).player.x[0] + ADD) == (*items).door.x[0] && (*items).door.len == 0)
		return ;
	(*items).player.x[0] += ADD;
}

void	s_key(items_t *items)
{
	int i = 0;

	(*items).player.path[16] = 'd';
	while (i < (*items).wall.len)
	{
		if (((*items).player.y[0] + ADD) == (*items).wall.y[i] && (*items).player.x[0] == (*items).wall.x[i])
			return;
		i++;
	}
	if (((*items).player.y[0] + ADD) == (*items).door.y[0] &&
		(*items).player.x[0] == (*items).door.x[0] && (*items).door.len == 0)
		return ;
	(*items).player.y[0] += ADD;
}

void move_player(int keycode, mlx_t *par)
{
	if (keycode == W)
		w_key(&par->items);
	else if (keycode == A)
		a_key(&par->items);
	else if (keycode == D)
		d_key(&par->items);
	else if (keycode == S)
		s_key(&par->items);
	// mlx_put_image_to_window(par->mlx, par->win, par->items.player.img, par->items.player.x[0], par->items.player.y[0]);
}

void update_player(mlx_t *param)
{
	static int c = '0';

	delay(4);
	if (c <= '9')
		param->items.player.path[18] = c++;
	else
		c = '0';
	mlx_put_image_to_window(param->mlx, param->win, param->items.player.img, param->items.player.x[0], param->items.player.y[0]);
}

