/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:14:39 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/08 19:17:41 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_empty(mlx_t *server)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	i = -1;
	while (i++ < server->items.empty.len)
	{
		x = server->items.empty.x[i];
		y = server->items.empty.y[i];
		img = server->items.empty.img;
		mlx_put_image_to_window(server->mlx, server->win, img, x, y);
	}
}

void	update_wall(mlx_t *server)
{
	int		i;
	int		x;
	int		y;
	void	*img;

	i = -1;
	while (i++ < server->items.wall.len)
	{
		x = server->items.wall.x[i];
		y = server->items.wall.y[i];
		img = server->items.wall.img;
		mlx_put_image_to_window(server->mlx, server->win, img, x, y);
	}
}

void	update_door(mlx_t *server)
{
	int		x;
	int		y;
	void	*img;

	x = server->items.door.x[0];
	y = server->items.door.y[0];
	img = server->items.door.img;
	mlx_put_image_to_window(server->mlx, server->win, img, x, y);
}

void	update_food(mlx_t *server)
{
	int			j;
	void		*img;
	int			x;
	int			y;
	static int	n;

	img = server->items.food.img;
	if (n++ == 1)
	{
		server->items.food.path[14] = '1';
		n = 0;
	}
	else
		server->items.food.path[14] = '0';
	j = -1;
	while (++j < server->items.food.len)
	{
		x = server->items.food.x[j];
		y = server->items.food.y[j];
		if (server->items.food.x[j] == -1)
			mlx_put_image_to_window(server->mlx, server->win,
				server->items.wall.img, 0, 0);
		else
			mlx_put_image_to_window(server->mlx, server->win, img, x, y);
	}
}
bool	check_wall_enemy(mlx_t *par, int x, int y)
{
	int	i;

	i = 0;
	while (i < (*par).items.wall.len)
	{
		if ((*par).items.wall.y[i] == y && ((*par).items.wall.x[i] == x))
			return (false);
		i++;
	}
	return (true);
}

bool	right(mlx_t *par, int i, bool is_up)
{
	if ((par->items.enemy.x[i] >= par->items.player.x[0] - (ADD * RNG)
		&& par->items.enemy.x[i] < par->items.player.x[0])
		&& par->items.enemy.y[i] == par->items.player.y[0]) // to be continue inshallah
	{

		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i] + ADD, par->items.enemy.y[i]))
		{
			par->items.enemy.x[i] += ADD;
			return (true);
		}
		printf("right\n");
		return (false);
	}
	return (false);
}

bool	left(mlx_t *par, int i, bool is_up)
{
	if (((par->items.enemy.x[i] <= par->items.player.x[0] + (ADD * RNG)
		&& par->items.enemy.x[i] > par->items.player.x[0])
		&& par->items.enemy.y[i] == par->items.player.y[0]) || is_up)
	{
		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i] - ADD, par->items.enemy.y[i]))
		{
			par->items.enemy.x[i] -= ADD;
			return (true);
		}
		printf("left\n");
		return (false);
	}
	return (false);
}

bool	up(mlx_t *par, int i)
{
	if ((par->items.enemy.y[i] >= par->items.player.y[0] - (ADD * RNG)
		&& par->items.enemy.y[i] < par->items.player.y[0])
		&& par->items.enemy.x[i] == par->items.player.x[0])
	{
		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i], par->items.enemy.y[i] + ADD))
		{
			par->items.enemy.y[i] += ADD;
			return (true);
		}
		if (left(par, i, true))
			return (true);
		if (right(par, i))
			return (true);
		printf("up\n");
		return (false);
	}
	return (false);
}

bool	down(mlx_t *par, int i)
{
	if ((par->items.enemy.y[i] <= par->items.player.y[0] + (ADD * RNG)
		&& par->items.enemy.y[i] > par->items.player.y[0])
		&& par->items.enemy.x[i] == par->items.player.x[0])
	{
		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i], par->items.enemy.y[i] - ADD))
		{
			par->items.enemy.y[i] -= ADD;
			return (true);
		}
		printf("down\n");
		return (false);
	}
	return (false);
}

bool	upleft(mlx_t *par, int i)
{
	if ((par->items.enemy.y[i] >= par->items.player.y[0] - (ADD * RNG)
		&& par->items.enemy.y[i] < par->items.player.y[0])
		&& (par->items.enemy.x[i] >= par->items.player.x[0] - (ADD * RNG)
		&& par->items.enemy.x[i] < par->items.player.x[0]))
	{
		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i] + ADD, par->items.enemy.y[i]))
		{
			par->items.enemy.x[i] += ADD;
			return (true);
		}
		if (check_wall_enemy(par, par->items.enemy.x[i], par->items.enemy.y[i] + ADD))
		{
			par->items.enemy.y[i] += ADD;
			return (true);
		}
		return (false);
	}
	return (false);
}

bool	upright(mlx_t *par, int i)
{
	if ((par->items.enemy.y[i] >= par->items.player.y[0] - (ADD * RNG)
		&& par->items.enemy.y[i] < par->items.player.y[0])
		&& (par->items.enemy.x[i] <= par->items.player.x[0] + (ADD * RNG)
		&& par->items.enemy.x[i] > par->items.player.x[0]))
	{
		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i] - ADD, par->items.enemy.y[i]))
		{
			par->items.enemy.x[i] -= ADD;
			return (true);
		}
		if (check_wall_enemy(par, par->items.enemy.x[i], par->items.enemy.y[i] + ADD))
		{
			par->items.enemy.y[i] += ADD;
			return (true);
		}
		printf("upright\n");
		return (false);
	}
	return (false);
}

bool	downleft(mlx_t *par, int i)
{
	if ((par->items.enemy.y[i] <= par->items.player.y[0] + (ADD * RNG)
		&& par->items.enemy.y[i] > par->items.player.y[0])
		&& (par->items.enemy.x[i] >= par->items.player.x[0] - (ADD * RNG)
		&& par->items.enemy.x[i] < par->items.player.x[0]))
	{
		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i] + ADD, par->items.enemy.y[i]))
		{
			par->items.enemy.x[i] += ADD;
			return (true);
		}
		if (check_wall_enemy(par, par->items.enemy.x[i], par->items.enemy.y[i] - ADD))
		{
			par->items.enemy.y[i] -= ADD;
			return (true);
		}
		printf("downleft\n");
		return (false);
	}
	return (false);
}

bool	downright(mlx_t *par, int i)
{
	if ((par->items.enemy.y[i] <= par->items.player.y[0] + (ADD * RNG)
		&& par->items.enemy.y[i] > par->items.player.y[0])
		&& (par->items.enemy.x[i] <= par->items.player.x[0] + (ADD * RNG)
		&& par->items.enemy.x[i] > par->items.player.x[0]))
	{
		mlx_put_image_to_window(par->mlx, par->win,
			par->items.empty.img, par->items.enemy.x[i],
			par->items.enemy.y[i]);
		if (check_wall_enemy(par, par->items.enemy.x[i] - ADD, par->items.enemy.y[i]))
		{
			par->items.enemy.x[i] -= ADD;
			return (true);
		}
		if (check_wall_enemy(par, par->items.enemy.x[i], par->items.enemy.y[i] - ADD))
		{
			par->items.enemy.y[i] -= ADD;
			return (true);
		}
		printf("downright\n");
		return (false);
	}
	return (false);
}

void	move_enemy(mlx_t *server)
{
	int	i;

	i = -1;
	while (++i < server->items.enemy.len)
	{

		if (!upleft(server, i))
			if (!upright(server, i))
				if (!downleft(server, i))
					if (!downright(server, i))
						if (!right(server, i))
							if (!left(server, i, false))
								if (!up(server, i))
									if (!down(server, i))
										continue;
		break;
	}
}

void	update_enemy(mlx_t *server)
{
	static int	c = '0';
	int			j;

	if (c <= '4')
		server->items.enemy.path[19] = c++;
	else
		c = '0';
	j = -1;
	while (++j < server->items.enemy.len)
	{
		mlx_put_image_to_window(server->mlx, server->win,
			server->items.enemy.img, server->items.enemy.x[j],
			server->items.enemy.y[j]);
	}
}
