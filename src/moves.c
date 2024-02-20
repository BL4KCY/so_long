/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:49:28 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 15:54:34 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_moves(t_mlx *server)
{
	static int	move = -1;

	if (move != server->moves)
	{
		move = server->moves;
		ft_printf("moves :\t(%d) |\n", move);
	}
}
