/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:50:43 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/11 21:51:42 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_items(t_mlx *param)
{
	if (param->items.empty.x)
		free(param->items.empty.x);
	if (param->items.empty.y)
		free(param->items.empty.y);
	if (param->items.wall.x)
		free(param->items.wall.x);
	if (param->items.wall.y)
		free(param->items.wall.y);
	if (param->items.door.x)
		free(param->items.door.x);
	if (param->items.door.y)
		free(param->items.door.y);
	if (param->items.food.x)
		free(param->items.food.x);
	if (param->items.food.y)
		free(param->items.food.y);
	if (param->items.player.x)
		free(param->items.player.x);
	if (param->items.player.y)
		free(param->items.player.y);
	if (param->items.enemy.x)
		free(param->items.enemy.x);
	if (param->items.enemy.y)
		free(param->items.enemy.y);
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
	ft_lstclear(&param->map, free);
	if (status == MALLOC_ERROR || status == WIN_ERROR)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
