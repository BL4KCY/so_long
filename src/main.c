#include "so_long.h"
// #include <X11/keysym.h>
# define HIGHT 720
# define WIDTH 480
#include <stdio.h>

int	keyboard(int keycode, t_mlx *param)
{
	if (keycode == ESC)
	{
		printf("key number {%d} (ESC) pressed!",keycode);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 49)
	{
		mlx_string_put(param->mlx, param->win, 50, 50, 0x00F24810, "MUSTAPHA");
	}
	if (keycode == 50)
	{
		mlx_string_put(param->mlx, param->win, 150, 50, 0x00024810, "OUSSAMA");
	}
	else
		printf("key number {%d} pressed!\n", keycode);
	return (0);
}

int	mouse(int mousekey, t_mlx *param)
{
	printf("the key number {%d} in mouse pressed!\n",mousekey);
	return (param - param);
}

int	main(void)
{
	t_mlx	server;

	server.mlx = mlx_init();
	if (server.mlx == NULL)
		return (EXIT_FAILURE);
	server.win = mlx_new_window(server.mlx, HIGHT, WIDTH, "so_long");
	if (server.win == NULL)
	{
		mlx_destroy_display(server.mlx);
		free(server.mlx);
		return (MALLOC_ERROR);
	}
	mlx_key_hook(server.win, keyboard, &server);
	mlx_mouse_hook(server.win, mouse, &server);
	mlx_loop(server.mlx);
}
