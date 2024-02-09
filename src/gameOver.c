/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameOver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:36:10 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/09 09:31:47 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



// void	winder(mlx_t *server)
// {
// 	int  i;
// 	char	*nbr;
// 	char	*buff;

// 	i = 0;
// 	server->win = mlx_new_window(server->mlx, 480, 480, "Winer");
// 	char	path[100];
// 	ft_strlcpy(path, "srcs/texture/winer/", 100);
// 	while (i < 36)
// 	{
// 		nbr = ft_itoa(i);
// 		buff = ft_strjoin(path, nbr);
// 		server->items.empty.img = mlx_xpm_file_to_image(server->mlx, buff, &server->items.empty.x[0], &server->items.empty.y[0]);
// 		mlx_put_image_to_window(server->mlx, server->win, server->items.empty.img, 0, 0);
// 		mlx_destroy_image(server->mlx, server->items.empty.img);
// 		free(nbr);
// 		free(buff);
// 		i++;
// 		delay(3);
// 	}
// }

// // void	over(mlx_t *server)
// // {

// // }


void	gameover(mlx_t *server)
{
	if (server->gameover)
		printf("gameover\n");
	else
		printf("winer\n");
	ft_exit(server);
}
