/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:49:28 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/03 08:51:50 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void increase_moves(t_mlx *param, int keycode)
{
	if (keycode == W)
	{
		if (((*param).y - ADD) >= 0)
			(*param).moves++;
	}
	if (keycode == A)
	{
		if (((*param).x - ADD) >= 0)
			(*param).moves++;
	}
	if (keycode == D)
	{
		if (((*param).x + ADD) < (*param).width && ((2 * ADD) + (*param).x) <= (*param).width)
			(*param).moves++;
	}
	if (keycode == S)
	{
		if (((*param).y + ADD) < (*param).hight && ((2 * ADD) + (*param).y) <= (*param).hight)
			(*param).moves++;
	}
}

void update_moves(t_mlx *server)
{
	char *moves;
	char str[100];

	ft_strlcpy(str, "Moves: ", 100);
	moves = ft_itoa(server->moves);
	ft_strlcat(str, moves, 100);
	mlx_string_put(server->mlx, server->win, 10, 10, 0x00FF0000, str);
	free(moves);
}
