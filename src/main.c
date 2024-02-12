/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:17:35 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/12 15:20:20 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	server;

	if (argc != 2)
		ERR("Error\nInvalid number of arguments");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		ERR("Error\nInvalid file");
	map_parse(argv[1], &server);
	server.mlx = mlx_init();
	if (server.mlx == NULL)
		ERR("Error\nmlx_init() failed\n");
	init_game(&server);
	mlx_hook(server.win, ON_KEYDOWN, KEYPRESSMASK, keyboard, &server);
	mlx_hook(server.win, ON_DESTROY, KEYPRESSMASK, ft_exit, &server);
	mlx_loop_hook(server.mlx, render_next_frame, &server);
	mlx_loop(server.mlx);
}
