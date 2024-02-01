#include "so_long.h"
// #include <X11/keysym.h>
# define HIGHT 800
# define WIDTH 800
# define ADD 40
#include <stdio.h>
#include <unistd.h>

int	ft_exit(t_mlx *param)
{
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	ft_lstclear(&param->map, free);
	free(param->mlx);
	exit(EXIT_SUCCESS);
}

int	keyboard(int keycode, t_mlx *param)
{
	if (keycode == ESC)
	{
		printf("key number {%d} (ESC) pressed!",keycode);
		ft_exit(param);
	}
	if (keycode == W)
		if (((*param).y - ADD) >= 0)
			(*param).y -= ADD;
	if (keycode == A)
		if (((*param).x - ADD) >= 0)
			(*param).x -= ADD;
	if (keycode == D)
		if (((*param).x + ADD) < (*param).width && ((2 * ADD) + (*param).x) <= (*param).width)
			(*param).x += ADD;
	if (keycode == S)
		if (((*param).y + ADD) < (*param).hight && ((2 * ADD) + (*param).y) <= (*param).hight)
			(*param).y += ADD;
	return (0);
}



int	mouse(int mousekey, t_mlx *param)
{
	printf("the key number {%d} in mouse pressed!\n",mousekey);
	return (param - param);
}
void	init_game(t_mlx *server)
{
	ft_strlcpy(server->pathxpm, "img/pacx40/1.xpm", 100);
	server->width = ft_strlen(server->map->content) * ADD;
	server->hight = ft_lstsize(server->map) * ADD;
}

int	render_next_frame(t_mlx *server)
{

	int	w,h;
	server->img = mlx_xpm_file_to_image(server->mlx, "img/pacx40/1.xpm", &w, &h);
	mlx_clear_window(server->mlx, server->win);
	mlx_put_image_to_window(server->mlx, server->win, server->img, (*server).x, (*server).y);
	mlx_destroy_image(server->mlx, server->img);
	return (0);
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
	server.win = mlx_new_window(server.mlx, server.width, server.hight, "so_long");
	if (server.win == NULL)
	{
		mlx_destroy_display(server.mlx);
		free(server.mlx);
		return (MALLOC_ERROR);
	}
	mlx_hook(server.win, ON_KEYUP, KeyReleaseMask, keyboard, &server);
	mlx_hook(server.win, ON_MOUSEDOWN, ButtonPressMask, mouse, &server);
	mlx_hook(server.win, ON_DESTROY, KeyPressMask, ft_exit, &server);
	mlx_loop_hook(server.mlx, render_next_frame, &server);
	mlx_loop(server.mlx);
}
