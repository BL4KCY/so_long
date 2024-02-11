/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:10 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/11 21:44:25 by melfersi         ###   ########.fr       */
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
# define MAX_HEIGHT 1080
# define MAX_WIDTH 1950

// macros for errors
# define ERR(errmsg) {ft_putendl_fd(errmsg, STDERR_FILENO); exit(EXIT_FAILURE);}

// structs
typedef struct
{
	int			*x;
	int			*y;
	int			len;
	char		path[100];
	void		*img;
}	t_coor;

typedef struct
{
	t_coor	player;
	t_coor	enemy;
	t_coor	food;
	t_coor	empty;
	t_coor	wall;
	t_coor	door;
}	t_items;

typedef struct
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		score;
	t_items	items;
	t_list	*map;
	int		moves;
	bool	lock;
	bool	lose;
	bool	won;
	bool	enemy_moved;
	int		enemy_dir[2];
}	t_mlx;

typedef struct
{
	int x;
	int y;
}	t_point;

// enums
enum e_status
{
	MALLOC_ERROR,
	WIN_ERROR,
	WINER,
	LOSER,
	ESCAPE_PRESS,
	INVALID_MAP
};
// prototypes
int		ft_exit(t_mlx *param, int status);
void	gameover(t_mlx *server, int status);
void	empty_init(t_coor *empty, int x, int y);
void	wall_init(t_coor *wall, int x, int y);
void	door_init(t_coor *door, int x, int y);
void	food_init(t_coor *food, int x, int y);
void	enemy_init(t_coor *enemy, int x, int y);
void	init_game(t_mlx *server);
void	coordinate_init(t_mlx *server, t_list *map, int x, int y);
void	player_init(t_coor *player, int x, int y);
int		keyboard(int keycode, t_mlx *param);
void	update_moves(t_mlx *server);
void	w_key(t_mlx *par);
void	a_key(t_mlx *par);
void	d_key(t_mlx *par);
void	s_key(t_mlx *par);
void 	move_player(int keycode, t_mlx *par);
void	check_food(t_mlx *par);
bool	check_wall(t_mlx *par, int add, bool is_x);
bool	check_door(t_mlx *par, int add, bool is_x);
void	check_enemy(t_mlx *par);
void	update_player(t_mlx *param);
void	update_empty(t_mlx *server);
void	update_wall(t_mlx *server);
void	update_door(t_mlx *server);
void	update_food(t_mlx *server);
void	update_enemy(t_mlx *server);
int		render_next_frame(t_mlx *server);
void	animation(t_mlx *server);
void	images_slayer(t_mlx *server);
void	delay(size_t ms);
void	map_parse(char *path, t_mlx *par);
void	move_enemy(t_mlx *server);
bool	right(t_mlx *par, int i);
bool	left(t_mlx *par, int i);
bool	up(t_mlx *par, int i);
bool	down(t_mlx *par, int i);
bool	upleft(t_mlx *par, int i);
bool	upright(t_mlx *par, int i);
bool	downleft(t_mlx *par, int i);
bool	downright(t_mlx *par, int i);
bool	check_wall_enemy(t_mlx *par, int x, int y, int index);
void	allocate_coors(t_mlx *server);
void	set_null(t_mlx *server);
void	free_items(t_mlx *param);
void	check_path(t_mlx *par);
char	**copy_map(t_mlx *par, t_list *map);
bool	door_path(t_mlx *par, char **copy);
bool	food_path(t_mlx *par, char **copy);
void	ft_free2d(char **map);
void	flood_fill(char **map, int x, int y);
char	**copy_map(t_mlx *par, t_list *map);
bool	is_valid_path(t_mlx *par, char **copy);
#endif

