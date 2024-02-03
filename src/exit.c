/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:50:43 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/03 08:59:25 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_exit(t_mlx *param)
{
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	ft_lstclear(&param->map, free);
	free(param->mlx);
	exit(EXIT_SUCCESS);
}