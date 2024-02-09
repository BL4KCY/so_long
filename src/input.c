/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:47:29 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/09 19:00:24 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	arrow_keys(int *keycode);

int	keyboard(int keycode, mlx_t *param)
{
	arrow_keys(&keycode);
	if (keycode == ESC)
		ft_exit(param, ESCAPE_PRESS);
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

void	set_null(mlx_t *server)
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
	server->items.enemy.x = NULL;
	server->items.enemy.y = NULL;
}
