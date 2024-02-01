/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:10 by melfersi          #+#    #+#             */
/*   Updated: 2024/02/01 09:51:49 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
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
# define MALLOC_ERROR 1
# define ESC 65307
# define BACK_SPACE 65288
# define W 119
# define S 115
# define A 97
# define D 100

// struct for mlx image
typedef struct
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
// struct for mlx data
typedef struct
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_mlx;

// prototypes

t_list	*map_parse(char *path);






#endif
