/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:49:28 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 16:15:31 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_moves(t_mlx *server)
{
	char		str[100];
	char		*moves;
	static int	move = -1;

	moves = ft_itoa(server->moves);
	ft_strlcpy(str, "Moves: ", 100);
	ft_strlcat(str, moves, 100);
	if (move != server->moves)
	{
		move = server->moves;
		mlx_put_image_to_window(server->mlx, server->win,
			server->items.wall.img, 0, 0);
		mlx_put_image_to_window(server->mlx, server->win,
			server->items.wall.img, ADD, 0);
		mlx_put_image_to_window(server->mlx, server->win,
			server->items.wall.img, ADD * 2, 0);
		mlx_string_put(server->mlx, server->win, 0, ADD - 25, 0x00FF00, str);
	}
	free(moves);
}
