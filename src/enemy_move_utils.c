/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:47:17 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/10 18:27:51 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_wall_enemy(t_mlx *par, int x, int y, int index)
{
	int	i;

	i = 0;
	while (i < (*par).items.wall.len)
	{
		if ((*par).items.wall.y[i] == y && ((*par).items.wall.x[i] == x))
			return (false);
		i++;
	}
	i = 0;
	while (i < (*par).items.enemy.len)
	{
		if (i != index && (*par).items.enemy.y[i] == y
			&& ((*par).items.enemy.x[i] == x))
			return (false);
		i++;
	}
	if (x == (*par).items.door.x[0] && y == (*par).items.door.y[0])
		return (false);
	return (true);
}

bool	upleft(t_mlx *par, int i)
{
	if ((par->items.enemy.y[i] >= par->items.player.y[0] - (ADD * RNG)
			&& par->items.enemy.y[i] < par->items.player.y[0])
		&& (par->items.enemy.x[i] >= par->items.player.x[0] - (ADD * RNG)
			&& par->items.enemy.x[i] < par->items.player.x[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i] + ADD,
				par->items.enemy.y[i], i))
		{
			par->items.enemy.x[i] += ADD;
			return (true);
		}
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

bool	upright(t_mlx *par, int i)
{
	if ((par->items.enemy.y[i] >= par->items.player.y[0] - (ADD * RNG)
			&& par->items.enemy.y[i] < par->items.player.y[0])
		&& (par->items.enemy.x[i] <= par->items.player.x[0] + (ADD * RNG)
			&& par->items.enemy.x[i] > par->items.player.x[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i] - ADD,
				par->items.enemy.y[i], i))
		{
			par->items.enemy.x[i] -= ADD;
			return (true);
		}
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

bool	downleft(t_mlx *par, int i)
{
	if ((par->items.enemy.y[i] <= par->items.player.y[0] + (ADD * RNG)
			&& par->items.enemy.y[i] > par->items.player.y[0])
		&& (par->items.enemy.x[i] >= par->items.player.x[0] - (ADD * RNG)
			&& par->items.enemy.x[i] < par->items.player.x[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i] + ADD,
				par->items.enemy.y[i], i))
		{
			par->items.enemy.x[i] += ADD;
			return (true);
		}
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

bool	downright(t_mlx *par, int i)
{
	if ((par->items.enemy.y[i] <= par->items.player.y[0] + (ADD * RNG)
			&& par->items.enemy.y[i] > par->items.player.y[0])
		&& (par->items.enemy.x[i] <= par->items.player.x[0] + (ADD * RNG)
			&& par->items.enemy.x[i] > par->items.player.x[0]))
	{
		if (check_wall_enemy(par, par->items.enemy.x[i] - ADD,
				par->items.enemy.y[i], i))
		{
			par->items.enemy.x[i] -= ADD;
			return (true);
		}
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
