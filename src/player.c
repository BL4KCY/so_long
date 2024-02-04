/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:19:16 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/04 18:35:33 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(int keycode, mlx_t *par)
{
	if (keycode == W)
	{
		if (((*par).items.player.y[0] - ADD) >= 0)
			(*par).items.player.y[0] -= ADD;
		(*par).items.player.path[16] = 'u';
	}
	if (keycode == A)
	{
		if (((*par).items.player.x[0] - ADD) >= 0)
			(*par).items.player.x[0] -= ADD;
		(*par).items.player.path[16] = 'l';

	}
	if (keycode == D)
	{
		if (((*par).items.player.x[0] + ADD) < (*par).width && ((2 * ADD) + (*par).items.player.x[0]) <= (*par).width)
			(*par).items.player.x[0] += ADD;
		(*par).items.player.path[16] = 'r';
	}
	if (keycode == S)
	{
		if (((*par).items.player.y[0] + ADD) < (*par).hight && ((2 * ADD) + (*par).items.player.y[0]) <= (*par).hight)
			(*par).items.player.y[0] += ADD;
		(*par).items.player.path[16] = 'd';
	}
}

void update_player(mlx_t *param)
{
	mlx_put_image_to_window(param->mlx, param->win, param->items.player.img, param->items.player.x[0], param->items.player.y[0]);
}

