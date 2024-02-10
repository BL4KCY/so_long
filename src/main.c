/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/10 11:59:02 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	mlx_t	server;

	if (argc != 2)
		ERR("Error\nInvalid number of arguments");
	map_parse(argv[1], &server);
	check_path(&server);
	server.mlx = mlx_init();
	if (server.mlx == NULL)
		ERR("Error\nmlx_init() failed\n");
	init_game(&server);
	mlx_hook(server.win, ON_KEYDOWN, KeyPressMask, keyboard, &server);
	mlx_hook(server.win, ON_DESTROY, KeyPressMask, ft_exit, &server);
	mlx_loop_hook(server.mlx, render_next_frame, &server);
	mlx_loop(server.mlx);
}
