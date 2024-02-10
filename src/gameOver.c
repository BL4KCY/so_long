/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameOver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:36:10 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/10 18:28:24 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	winer_screen(t_mlx *param, int *ind, int *j);
static void	loser_screen(t_mlx *param, int *ind, int *j);

void	gameover(t_mlx *server, int status)
{
	static int	i = 0;
	static int	j = 0;

	if (i < 10000)
	{
		if (status == WINER)
		{
			if (j++ == 10000)
				winer_screen(server, &i, &j);
		}
		else if (status == LOSER)
		{
			if (j++ == 10000)
				loser_screen(server, &i, &j);
		}
		else
			ft_exit(server, status);
	}
	else
		ft_exit(server, status);
}

static void	loser_screen(t_mlx *param, int *ind, int *j)
{
	static int	i = 1;
	void		*img;
	int			x;
	int			y;
	char		*buff;

	if (i == 57)
		ft_exit(param, LOSER);
	param->items.food.img = ft_itoa(i);
	buff = ft_strjoin("textures/loser/", param->items.food.img);
	img = mlx_xpm_file_to_image(param->mlx, buff, &x, &y);
	mlx_put_image_to_window(param->mlx, param->win,
		img, param->width / 3 + 23, param->height / 4);
	mlx_destroy_image(param->mlx, img);
	free(param->items.food.img);
	free(buff);
	i++;
	(*j) = 0;
	(*ind)++;
}

static void	winer_screen(t_mlx *param, int *ind, int *j)
{
	static int	i = 1;
	void		*img;
	int			x;
	int			y;
	char		*buff;

	if (i == 37)
		ft_exit(param, WINER);
	param->items.food.img = ft_itoa(i);
	buff = ft_strjoin("textures/winer/", param->items.food.img);
	img = mlx_xpm_file_to_image(param->mlx, buff, &x, &y);
	mlx_put_image_to_window(param->mlx, param->win,
		img, param->width / 3 + 23, param->height / 4);
	mlx_destroy_image(param->mlx, img);
	free(param->items.food.img);
	free(buff);
	i++;
	(*j) = 0;
	(*ind)++;
}
