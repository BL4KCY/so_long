/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:05:31 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/08 08:57:13 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key(mlx_t *par)
{
	(*par).items.player.path[16] = 'u';
	if (!check_wall(par, -ADD, false) || !check_door(par, -ADD, false))
		return ;
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img,
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
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img,
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
	mlx_put_image_to_window(par->mlx, par->win, par->items.empty.img,
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

void	move_player(int keycode, mlx_t *par)
{
	if (keycode == W)
		w_key(par);
	if (keycode == A)
		a_key(par);
	if (keycode == D)
		d_key(par);
	if (keycode == S)
		s_key(par);
	check_enemy(par);
	if ((*par).score == 0)
		(*par).lock = false;
}
