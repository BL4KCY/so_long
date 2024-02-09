/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:10 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/09 20:27:12 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"
// macros for mlx functions
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17
// macros for mlx hooks
# define NoEventMask 0L
# define KeyPressMask (1L<<0)
# define KeyReleaseMask (1L<<1)
# define ButtonPressMask (1L<<2)
# define ButtonReleaseMask (1L<<3)
# define EnterWindowMask (1L<<4)
# define LeaveWindowMask (1L<<5)
# define PointerMotionMask (1L<<6)
# define PointerMotionHintMask (1L<<7)
# define Button1MotionMask (1L<<8)
# define Button2MotionMask (1L<<9)
# define Button3MotionMask (1L<<10)
# define Button4MotionMask (1L<<11)
# define Button5MotionMask (1L<<12)
# define ButtonMotionMask (1L<<13)
# define KeymapStateMask (1L<<14)
# define ExposureMask (1L<<15)
# define VisibilityChangeMask (1L<<16)
# define StructureNotifyMask (1L<<17)
# define ResizeRedirectMask (1L<<18)
# define SubstructureNotifyMask (1L<<19)
# define SubstructureRedirectMask (1L<<20)
# define FocusChangeMask (1L<<21)
# define PropertyChangeMask (1L<<22)
# define ColormapChangeMask (1L<<23)
# define OwnerGrabButtonMask (1L<<24)
// macros for mlx keycodes
# define ESC 65307
# define BACK_SPACE 65288
# define W 119
# define S 115
# define A 97
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ADD 50
# define FPS 30
# define RNG 4

// macros for errors
# define ERR(errmsg) {ft_putendl_fd(errmsg, STDERR_FILENO); exit(EXIT_FAILURE);}

// structs
typedef struct coor_s
{
	int			*x;
	int			*y;
	int			len;
	char		path[100];
	void		*img;
}	coor_t;

typedef struct items_s
{
	coor_t	player;
	coor_t	enemy;
	coor_t	food;
	coor_t	empty;
	coor_t	wall;
	coor_t	door;
}	items_t;

typedef struct mlx_s
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		score;
	items_t	items;
	t_list	*map;
	int		moves;
	bool	lock;
	bool	gameover;
	bool	enemy_moved;
	int		enemy_dir[2];
}	mlx_t;
// enums
enum e_status
{
	MALLOC_ERROR,
	WIN_ERROR,
	WINER,
	LOSER,
	ESCAPE_PRESS
};
// prototypes
int		ft_exit(mlx_t *param, int status);
void	gameover(mlx_t *server);
void	empty_init(coor_t *empty, int x, int y);
void	wall_init(coor_t *wall, int x, int y);
void	door_init(coor_t *door, int x, int y);
void	food_init(coor_t *food, int x, int y);
void	enemy_init(coor_t *enemy, int x, int y);
void	init_game(mlx_t *server);
void	coordinate_init(mlx_t *server, t_list *map, int x, int y);
void	player_init(coor_t *player, int x, int y);
int		keyboard(int keycode, mlx_t *param);
void	update_moves(mlx_t *server);
void	w_key(mlx_t *par);
void	a_key(mlx_t *par);
void	d_key(mlx_t *par);
void	s_key(mlx_t *par);
void 	move_player(int keycode, mlx_t *par);
void	check_food(mlx_t *par);
bool	check_wall(mlx_t *par, int add, bool is_x);
bool	check_door(mlx_t *par, int add, bool is_x);
void	check_enemy(mlx_t *par);
void	update_player(mlx_t *param);
void	update_empty(mlx_t *server);
void	update_wall(mlx_t *server);
void	update_door(mlx_t *server);
void	update_food(mlx_t *server);
void	update_enemy(mlx_t *server);
int		render_next_frame(mlx_t *server);
void	animation(mlx_t *server);
void	images_slayer(mlx_t *server);
void	delay(size_t ms);
void	map_parse(char *path, mlx_t *par);
void	move_enemy(mlx_t *server);
bool	right(mlx_t *par, int i);
bool	left(mlx_t *par, int i);
bool	up(mlx_t *par, int i);
bool	down(mlx_t *par, int i);
bool	upleft(mlx_t *par, int i);
bool	upright(mlx_t *par, int i);
bool	downleft(mlx_t *par, int i);
bool	downright(mlx_t *par, int i);
bool	check_wall_enemy(mlx_t *par, int x, int y, int index);
void	allocate_coors(mlx_t *server);
void	set_null(mlx_t *server);
#endif

