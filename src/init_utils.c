/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:28:56 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/07 13:33:08 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_init(coor_t *empty, int x, int y)
{
	static int	i = 0;

	if (i == 0)
		ft_strlcpy(empty->path, "textures/empty/empty.xpm", 100);
	empty->x[i] = x;
	empty->y[i] = y;
	empty->len = (++i);
}

void	wall_init(coor_t *wall, int x, int y)
{
	static int	i = 0;

	if (i == 0)
		ft_strlcpy(wall->path, "textures/wall/wall.xpm", 100);
	wall->x[i] = x;
	wall->y[i] = y;
	wall->len = (++i);
}

void	door_init(coor_t *door, int x, int y)
{
	ft_strlcpy(door->path, "textures/door/0.xpm", 100);
	door->x[0] = x;
	door->y[0] = y;
	door->len = 0;
}

void	food_init(coor_t *food, int x, int y)
{
	static int	i = 0;

	if (i == 0)
		ft_strlcpy(food->path, "textures/food/0.xpm", 100);
	food->x[i] = x;
	food->y[i] = y;
	food->len = (++i);
}

void	enemy_init(coor_t *enemy, int x, int y)
{
	static int	i = 0;

	if (i == 0)
		ft_strlcpy(enemy->path, "textures/enemy/bat/0.xpm", 100);
	enemy->x[i] = x;
	enemy->y[i] = y;
	enemy->len = (++i);
}
