/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:47:29 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/07 13:38:37 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	arrow_keys(int *keycode);

int	keyboard(int keycode, mlx_t *param)
{
	arrow_keys(&keycode);
	if (keycode == ESC)
	{
		printf("key number {%d} (ESC) pressed!", keycode);
		ft_exit(param);
	}
	move_player(keycode, param);
	return (0);
}

static void	arrow_keys(int *keycode)
{
	if (*keycode == UP)
		*keycode = W;
	if (*keycode == DOWN)
		*keycode = S;
	if (*keycode == LEFT)
		*keycode = A;
	if (*keycode == RIGHT)
		*keycode = D;
}
