/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:46:21 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/03 08:46:45 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_mlx *server)
{
	ft_strlcpy(server->pathxpm, "img/player/r/0.xpm", 100);
	(*server).x = 0;
	(*server).y = 0;
	(*server).moves = 0;
	server->width = ft_strlen(server->map->content) * ADD;
	server->hight = ft_lstsize(server->map) * ADD;
}
