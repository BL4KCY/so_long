/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:44:43 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/17 10:23:30 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_mlx *server)
{
	int	i;

	i = -1;
	while (++i < server->items.enemy.len)
	{
		server->enemy_dir[0] = server->items.enemy.x[i];
		server->enemy_dir[1] = server->items.enemy.y[i];
		if (!right(server, i))
			if (!left(server, i))
				if (!up(server, i))
					if (!down(server, i))
						if (!upleft(server, i))
							if (!upright(server, i))
								if (!downleft(server, i))
									if (!downright(server, i))
										continue ;
		server->enemy_moved = true;
		break ;
	}
}

bool	right(t_mlx *par, int i)
{
	if (((par->items.enemy.x[i] >= par->items.player.x[0] - (ADD * RNG)
				&& par->items.enemy.x[i] < par->items.player.x[0])
			&& par->items.enemy.y[i] == par->items.player.y[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i] + ADD,
				par->items.enemy.y[i], i))
		{
			par->items.enemy.x[i] += ADD;
			return (true);
		}
		return (false);
	}
	return (false);
}

bool	left(t_mlx *par, int i)
{
	if (((par->items.enemy.x[i] <= par->items.player.x[0] + (ADD * RNG)
				&& par->items.enemy.x[i] > par->items.player.x[0])
			&& par->items.enemy.y[i] == par->items.player.y[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i] - ADD,
				par->items.enemy.y[i], i))
		{
			par->items.enemy.x[i] -= ADD;
			return (true);
		}
		return (false);
	}
	return (false);
}

bool	up(t_mlx *par, int i)
{
	if (((par->items.enemy.y[i] >= par->items.player.y[0] - (ADD * RNG)
				&& par->items.enemy.y[i] < par->items.player.y[0])
			&& par->items.enemy.x[i] == par->items.player.x[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i],
				par->items.enemy.y[i] + ADD, i))
		{
			par->items.enemy.y[i] += ADD;
			return (true);
		}
		return (false);
	}
	return (false);
}

bool	down(t_mlx *par, int i)
{
	if (((par->items.enemy.y[i] <= par->items.player.y[0] + (ADD * RNG)
				&& par->items.enemy.y[i] > par->items.player.y[0])
			&& par->items.enemy.x[i] == par->items.player.x[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i],
				par->items.enemy.y[i] - ADD, i))
		{
			par->items.enemy.y[i] -= ADD;
			return (true);
		}
		return (false);
	}
	return (false);
}
