#include "so_long.h"
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

void	arrow_keys(int *keycode)
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

void	incrase_moves(t_mlx *param, int keycode)
{
	if (keycode == W)
	{
		if (((*param).y - ADD) >= 0)
			(*param).moves++;
	}
	if (keycode == A)
	{
		if (((*param).x - ADD) >= 0)
			(*param).moves++;
	}
	if (keycode == D)
	{
		if (((*param).x + ADD) < (*param).width && ((2 * ADD) + (*param).x) <= (*param).width)
			(*param).moves++;
	}
	if (keycode == S)
	{
		if (((*param).y + ADD) < (*param).hight && ((2 * ADD) + (*param).y) <= (*param).hight)
			(*param).moves++;
	}
}
void	move_player(int keycode, t_mlx *param)
{
	if (keycode == W)
	{
		if (((*param).y - ADD) >= 0)
			(*param).y -= ADD;
		param->pathxpm[11] = 'u';
	}
	if (keycode == A)
	{
		if (((*param).x - ADD) >= 0)
			(*param).x -= ADD;
		param->pathxpm[11] = 'l';
	}
	if (keycode == D)
	{
		if (((*param).x + ADD) < (*param).width && ((2 * ADD) + (*param).x) <= (*param).width)
			(*param).x += ADD;
		param->pathxpm[11] = 'r';
	}
	if (keycode == S)
	{
		if (((*param).y + ADD) < (*param).hight && ((2 * ADD) + (*param).y) <= (*param).hight)
			(*param).y += ADD;
		param->pathxpm[11] = 'd';
	}
	incrase_moves(param, keycode);
}

int	keyboard(int keycode, t_mlx *param)
{
	arrow_keys(&keycode);
	if (keycode == ESC)
	{
		printf("key number {%d} (ESC) pressed!",keycode);
		ft_exit(param);
	}
	move_player(keycode, param);
	return (0);
}

void	update_player(t_mlx *param)
{
	mlx_clear_window(param->mlx, param->win);
	mlx_put_image_to_window(param->mlx, param->win, param->img, (*param).x, (*param).y);
}

int	mouse(int mousekey, t_mlx *param)
{
	printf("the key number {%d} in mouse pressed!\n",mousekey);
	return (param - param);
}
void	init_game(t_mlx *server)
{
	ft_strlcpy(server->pathxpm, "img/player/r/0.xpm", 100);
	(*server).x = 0;
	(*server).y = 0;
	(*server).moves = 0;
	server->width = ft_strlen(server->map->content) * ADD;
	server->hight = ft_lstsize(server->map) * ADD;
}

void	update_moves(t_mlx *server)
{
	char	*moves;
	char	str[100];

	ft_strlcpy(str, "Moves: ", 100);
	moves = ft_itoa(server->moves);
	ft_strlcat(str, moves, 100);
	mlx_string_put(server->mlx, server->win, 10, 10, 0x00FF0000, str);
	free(moves);
}

int	render_next_frame(t_mlx *server)
{
	static char	c = '0';
	int	w,h;

	for (long j = 0; j < 100000000; j++)
	{
	}
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
