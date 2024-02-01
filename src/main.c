#include "so_long.h"
// #include <X11/keysym.h>
# define HIGHT 800
# define WIDTH 800
# define ADD 50
#include <stdio.h>
#include <unistd.h>

int	keyboard(int keycode, t_mlx *param)
{
	static int	x;
	static int	y;
	int	w,h;
	param->img = mlx_xpm_file_to_image(param->mlx, "img/packmanpng.xpm", &w, &h);
	if (keycode == ESC)
	{
		printf("key number {%d} (ESC) pressed!",keycode);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W)
		if ((y - h) >= 0)
			y -= h;
	if (keycode == A)
		if ((x - w) >= 0)
			x -= w;
	if (keycode == D)
		if ((x + w) < HIGHT && ((2 * w) + x) <= WIDTH)
			x += w;
	if (keycode == S)
		if ((y + h) < WIDTH && ((2 * h) + y) <= HIGHT)
			y += h;
	mlx_clear_window(param->mlx, param->win);
	mlx_put_image_to_window(param->mlx, param->win, param->img, x, y);
	mlx_destroy_image(param->mlx, param->img);
	return (0);
}

int	mouse(int mousekey, t_mlx *param)
{
	printf("the key number {%d} in mouse pressed!\n",mousekey);
	return (param - param);
}
void	init_game(t_mlx *server)
{
	server->x = 0;
	server->y = 0;
	server->width = ft_strlen(server->map->content) * ADD;
	server->hight = ft_lstsize(server->map) * ADD;
}

int	main(int argc, char **argv)
{
	t_mlx	server;

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
	server.win = mlx_new_window(server.mlx, WIDTH, HIGHT, "so_long");
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
