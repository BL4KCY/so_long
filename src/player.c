/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:19:16 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/03 08:51:23 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(int keycode, t_mlx *param)
{
	if (keycode == W)
	{
		if (((*param).y - ADD) >= 0)
			(*param).y -= ADD;
		param->pathxpm[11] = 'u';
	}
	if (keycode == A)
	{
		if (((*param).x - ADD) >= 0)
			(*param).x -= ADD;
		param->pathxpm[11] = 'l';
	}
	if (keycode == D)
	{
		if (((*param).x + ADD) < (*param).width && ((2 * ADD) + (*param).x) <= (*param).width)
			(*param).x += ADD;
		param->pathxpm[11] = 'r';
	}
	if (keycode == S)
	{
		if (((*param).y + ADD) < (*param).hight && ((2 * ADD) + (*param).y) <= (*param).hight)
			(*param).y += ADD;
		param->pathxpm[11] = 'd';
	}
	increase_moves(param, keycode);
}

void update_player(t_mlx *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_put_image_to_window(param->mlx, param->win, param->img, (*param).x, (*param).y);
}
