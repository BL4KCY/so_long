/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:47:29 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 13:33:20 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	arrow_keys(int *keycode);

int	keyboard(int keycode, t_mlx *param)
{
	arrow_keys(&keycode);
	if (keycode == ESC)
		gameover(param, ESCAPE_PRESS);
	if (!(param->won))
		move_player(keycode, param);
	return (0);
}

static void	arrow_keys(int *keycode)
{
	if (*keycode == UP)
		*keycode = W;
	if (*keycode == DOWN)
		*keycode = S;
	if (*keycode == LEFT)
		*keycode = A;
	if (*keycode == RIGHT)
		*keycode = D;
}

void	set_null(t_mlx *server)
{
	server->items.empty.x = NULL;
	server->items.empty.y = NULL;
	server->items.wall.x = NULL;
	server->items.wall.y = NULL;
	server->items.door.x = NULL;
	server->items.door.y = NULL;
	server->items.food.x = NULL;
	server->items.food.y = NULL;
	server->items.player.x = NULL;
	server->items.player.y = NULL;
}
