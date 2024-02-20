/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameOver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:36:10 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/20 13:36:52 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	winer_screen(t_mlx *param, int *ind, int *j);

void	gameover(t_mlx *server, int status)
{
	static int	i = 0;
	static int	j = 0;

	if (i < 40)
	{
		if (status == WINER)
		{
			if (j++ == 10000)
				winer_screen(server, &i, &j);
		}
		else
			ft_exit(server, status);
	}
	else
		ft_exit(server, status);
}

static void	winer_screen(t_mlx *param, int *ind, int *j)
{
	static int	i = 1;
	void		*img;
	int			x;
	int			y;
	char		*buff;

	if (i == 41)
		ft_exit(param, WINER);
	param->items.food.img = ft_itoa(i);
	buff = ft_strjoin("textures/winner/", param->items.food.img);
	img = mlx_xpm_file_to_image(param->mlx, buff, &x, &y);
	mlx_put_image_to_window(param->mlx, param->win,
		img, (param->width / 2) - ((ADD * 2) + (ADD / 2)),
		(param->height / 2) - (ADD / 2));
	mlx_destroy_image(param->mlx, img);
	free(param->items.food.img);
	free(buff);
	i++;
	(*j) = 0;
	(*ind)++;
}
