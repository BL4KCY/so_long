/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:20:45 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/03 09:01:15 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delay(size_t ms);

int	render_next_frame(t_mlx *server)
{
	static char	c = '0';
	int	w,h;

	delay(2);
	server->img = mlx_xpm_file_to_image(server->mlx, server->pathxpm, &w, &h);
	if (server->img == NULL)
		ft_exit(server);
	update_player(server);
	update_moves(server);
	mlx_destroy_image(server->mlx, server->img);
	if (c <= '9')
		server->pathxpm[13] = c;
	else
		c = '0';
	c++;
	return (0);
}

static void delay(size_t ms)
{
	ms *= 48000000;
	while (ms--)
		;
}
