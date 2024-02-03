#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	t_mlx server;

	if (argc != 2)
	{
		ft_putendl_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	server.map = map_parse(argv[1]);
	init_game(&server);
	server.mlx = mlx_init();
	if (server.mlx == NULL)
		return (EXIT_FAILURE);
	server.win = mlx_new_window(server.mlx, server.width, server.hight, "so_long");
	if (server.win == NULL)
	{
		mlx_destroy_display(server.mlx);
		free(server.mlx);
		return (MALLOC_ERROR);
	}
	mlx_hook(server.win, ON_KEYUP, KeyReleaseMask, keyboard, &server);
	// mlx_hook(server.win, ON_MOUSEDOWN, ButtonPressMask, mouse, &server);
	mlx_hook(server.win, ON_DESTROY, KeyPressMask, ft_exit, &server);
	mlx_loop_hook(server.mlx, render_next_frame, &server);
	mlx_loop(server.mlx);
}
