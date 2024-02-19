/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:50:43 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/18 16:12:41 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ifnfree(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_items(t_mlx *param)
{
	ifnfree((void **)&param->items.empty.x);
	ifnfree((void **)&param->items.empty.y);
	ifnfree((void **)&param->items.wall.x);
	ifnfree((void **)&param->items.wall.y);
	ifnfree((void **)&param->items.food.x);
	ifnfree((void **)&param->items.food.y);
	ifnfree((void **)&param->items.player.x);
	ifnfree((void **)&param->items.player.y);
	ifnfree((void **)&param->items.enemy.x);
	ifnfree((void **)&param->items.enemy.y);
	ifnfree((void **)&param->items.door.x);
	ifnfree((void **)&param->items.door.y);
}

int	ft_exit(t_mlx *param, int status)
{
	free_items(param);
	mlx_destroy_image(param->mlx, param->items.empty.img);
	mlx_destroy_image(param->mlx, param->items.wall.img);
	if (status == MALLOC_ERROR)
		ft_putstr_fd("Error\nMalloc failed\n", 2);
	else if (status == WIN_ERROR)
		ft_putstr_fd("Error\nmlx_new_window() failed\n", 2);
	else if (status == WINER)
		ft_putstr_fd("You won!!\n", 1);
	else if (status == LOSER)
		ft_putstr_fd("You lose!!\n", 1);
	else if (status == INVALID_MAP)
		ft_putstr_fd("Error\nInvalid map\n", 2);
	else
		ft_putstr_fd("Game Ended!!\n", 1);
	if (status != INVALID_MAP)
		mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	ft_lstclear(&(param->map), free);
	if (status == MALLOC_ERROR || status == WIN_ERROR)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (status);
}
