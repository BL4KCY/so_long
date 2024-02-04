/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:49:28 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/04 17:57:09 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void increase_moves(mlx_t *param, int keycode)
{
	if (keycode == W)
	{
		if (((*param).items.player.x[0] - ADD) >= 0)
			(*param).moves++;
	}
	if (keycode == A)
	{
		if (((*param).items.player.x[0] - ADD) >= 0)
			(*param).moves++;
	}
	if (keycode == D)
	{
		if (((*param).items.player.x[0] + ADD) < (*param).width &&
			((2 * ADD) + (*param).items.player.x[0]) <= (*param).width)
			(*param).moves++;
	}
	if (keycode == S)
	{
		if (((*param).items.player.y[0] + ADD) < (*param).hight &&
			((2 * ADD) + (*param).items.player.y[0]) <= (*param).hight)
			(*param).moves++;
	}
	move_player(keycode, param);
}

void update_moves(mlx_t *server)
{
	char *moves;
	char str[100];

	ft_strlcpy(str, "Moves: ", 100);
	moves = ft_itoa(server->moves);
	ft_strlcat(str, moves, 100);
	mlx_string_put(server->mlx, server->win, 10, 10, 0x00FF0000, str);
	free(moves);
}
