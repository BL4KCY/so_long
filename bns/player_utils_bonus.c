/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:05:31 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 10:00:29 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	w_key(t_mlx *par)
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

void	a_key(t_mlx *par)
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

void	d_key(t_mlx *par)
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

void	s_key(t_mlx *par)
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

void	move_player(int keycode, t_mlx *par)
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
