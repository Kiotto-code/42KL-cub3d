/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:50:04 by yichan            #+#    #+#             */
/*   Updated: 2024/01/19 17:35:51 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include "color.h"
# include "mac_keycode.h"

# include "../libft/includes/libft.h"

/* Mac key codes */
//replaced using enum
// # define KEY_ESC	53
// # define KEY_W		13
// # define KEY_A		0
// # define KEY_S		1
// # define KEY_D		2
// # define KEY_UP		126
// # define KEY_LEFT	123
// # define KEY_DOWN	125
// # define KEY_RIGHT	124

# define SCREEN_WIDTH	1024
# define SCREEN_HEIGHT	576

/* Colors */
// # define WHITE		-1

struct s_coor
{
	int	y;
	int	x;
}	t_coor;

typedef struct s_object
{
	void	*img;
	int		width;
	int		height;
}	t_object;

//fucking YOU IDIOT PON PON
// typedef struct s_player
// {
// 	float	x;
// 	float	y;
// 	float	angle;
// 	float	delta_x;
// 	float	delta_y;
// }	t_player;

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	shift;
	int	mouse;
}	t_key;

typedef struct s_book
{
	void			*mlx;//mlx_init
	void			*win;//mlx_new_window
	// t_coor			winsize;
	struct s_coor	*winsize;
	unsigned int	winfps;
	const char		*file;//file_name
	char			**file_content;
	char			**elem_record;
	char			**map;
	t_key			*key;
}	t_book;

enum Status {
  SUCCESS,
  FAIL,
};

enum e_x11events
{
	KeyPress = 2,
	KeyRelease = 3,
	ButtonPress = 4,
	ButtonRelease = 5,
	MotionNotify = 6,
	EnterNotify = 7,
	LeaveNotify = 8,
	FocusIn = 9,
	FocusOut = 10,
	KeymapNotify = 11,
	Expose = 12,
	GraphicsExpose = 13,
	NoExpose = 14,
	VisibilityNotify = 15,
	CreateNotify = 16,
	DestroyNotify = 17,
	UnmapNotify = 18,
	MapNotify = 19,
	MapRequest = 20,
	ReparentNotify = 21,
	ConfigureNotify = 22,
	ConfigureRequest = 23,
	GravityNotify = 24,
	ResizeRequest = 25,
	CirculateNotify = 26,
	CirculateRequest = 27,
	PropertyNotify = 28,
	SelectionClear = 29,
	SelectionRequest = 30,
	SelectionNotify = 31,
	ColormapNotify = 32,
	ClientMessage = 33,
	MappingNotify = 34,
	GenericEvent = 35,
	LASTEvent = 36,
};

enum e_x11masks
{
	NoEventMask = 0L,
	KeyPressMask = (1L<<0),
	KeyReleaseMask = (1L<<1),
	ButtonPressMask = (1L<<2),
	ButtonReleaseMask = (1L<<3),
	EnterWindowMask = (1L<<4),
	LeaveWindowMask = (1L<<5),
	PointerMotionMask = (1L<<6),
	PointerMotionHintMask = (1L<<7),
	Button1MotionMask = (1L<<8),
	Button2MotionMask = (1L<<9),
	Button3MotionMask = (1L<<10),
	Button4MotionMask = (1L<<11),
	Button5MotionMask = (1L<<12),
	ButtonMotionMask = (1L<<13),
	KeymapStateMask = (1L<<14),
	ExposureMask = (1L<<15),
	VisibilityChangeMask = (1L<<16),
	StructureNotifyMask = (1L<<17),
	ResizeRedirectMask = (1L<<18),
	SubstructureNotifyMask = (1L<<19),
	SubstructureRedirectMask = (1L<<20),
	FocusChangeMask = (1L<<21),
	PropertyChangeMask = (1L<<22),
	ColormapChangeMask = (1L<<23),
	OwnerGrabButtonMask = (1L<<24),
};

//map_calidity.c
int	map_valid_wall_surround(t_book *record);
int	map_file_checking(t_book *record);

//map_find.c
int	map_find(t_book *record);

//cb3d_printer.c
int map_print(char **db_arr);

//mlx_window.c
void	open_image(t_book *record);

//mlx_window.c
int    image_update(void);


#endif