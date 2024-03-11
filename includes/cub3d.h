/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:50:04 by yichan            #+#    #+#             */
/*   Updated: 2024/03/11 14:42:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
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

// # define SCREEN_WIDTH	1024
// # define SCREEN_HEIGHT	576
# define FOV			60
# define WIN_W			1080
# define WIN_H			720
# define SCREEN_WIDTH	WIN_W
# define SCREEN_HEIGHT	WIN_H
# define RAY_NUM		WIN_W	
# define INTERSECTION_FOUND 1
# define DOOR_FOUND 2
# define CELL_SIZE 500
# define HALF_FOV 30
# define ANG_IN_D 0.05555555555
# define N 0
# define E 90
# define S 180
# define W 270
# define OPEN 3
# define CLOSE 4
/* Colors */
// # define WHITE		-1

typedef struct s_coor
{
	int	y;
	int	x;
}	t_coor;

// typedef struct s_object
// {
// 	void	*img;
// 	int		width;
// 	int		height;
// }	t_object;

typedef struct s_line_param
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_line_param;

// typedef struct s_map
// {
// 	char			**map_tab;
// 	char			*map_name; //map path
// 	int				map_h;
// 	int				map_w;
// 	int				map_vh;
// 	int				map_vw;
// 	int				pn;
// 	int				px;
// 	int				py;
// 	int				pv;
// 	char			*meta_data[6];
// 	int				flr[3]; //floor color
// 	int				cl[3]; //ceiling color
// 	unsigned long	int_f; //floor color in hexadecimal
// 	unsigned long	int_c; //ceiling color in hexadecimal
// }	t_map;

typedef struct s_map
{
	char			**map_tab;
	char			*map_name;
	int				map_h;
	int				map_w;
	int				map_vh;
	int				map_vw; //map_tab = map table, map_name = map name, map_h = map height, map_w = map width, map_vh = map virtual height, map_vw = map virtual width
	int				pn;
	int				px;
	int				py; 
	int				pv; //pn = player number, px = player x, py = player y, pv = player pov
	char			*meta_data[6]; //meta_data[0] = NO, meta_data[1] = SO, meta_data[2] = WE, meta_data[3] = EA, meta_data[4] = F, meta_data[5] = C
	int				flr[3];
	int				cl[3]; //flr and cl are the same as int_f and int_c but in decimal
	unsigned long	int_f;
	unsigned long	int_c; //int_f and int_c are the same as flr and cl but in hex
}	t_map;


typedef struct s_image
{
	void	*img;
	char	*addr; //data
	char	**d_arr;
	char	*path;
	int		bits_per_pixel;
	int		line_length; //bytes per row
	int		endian;
	int		width; //x
	int		height; //y
}	t_image;

typedef struct s_sprite
{
	t_image	n_img;
	t_image	s_img;
	t_image	e_img;
	t_image	w_img;
	t_image	o_door;
	t_image	c_door;
	t_image	side;
}	t_sprite;

typedef struct s_table
{
	double	*tan_table;
	double	*cos_table;
	double	*sin_table;
}				t_table;

typedef struct s_position
{
	int		x_cell; //player position
	int		y_cell; //player position
	double	virtual_px; //virtual player position
	double	virtual_py; //virtual player position
	double	pov; //player point of view
	t_map	*map;
}	t_position;

typedef struct s_ray
{
	int			door;
	int			first;
	int			v_skip;
	int			h_skip;
	double		x_save;
	double		y_save;
	double		ray_pov;
	int			index;
	double		xi ;
	double		yi ;
	double		xbound ;
	double		ybound;
	int			v_hit;
	int			h_hit;
	double		v_distance;
	double		h_distance;
	double		x_step;
	double		y_step;
	int			quadrant;
	int			xcell_v;
	int			ycell_v;
	int			xcell_h;
	int			ycell_h;
	double		save_distance;
	double		ray_h;
	t_position	*player;
}				t_ray;

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
	int	click;
	int	space;
	int	esc;
}	t_key; // key_state

// typedef struct s_keystate
// {
// 	int	tir;
// 	int	w;
// 	int	a;
// 	int	s;
// 	int	d;
// 	int	r;
// 	int	l;
// 	int	q;
// 	int	esc;
// 	// int	o;
// 	// int	c;
// 	// int	run;
// }	t_keystate;

typedef struct s_imgdata
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_texter;

// typedef struct s_images
// {
// 	t_texter	n_img;
// 	t_texter	s_img;
// 	t_texter	e_img;
// 	t_texter	w_img;
// 	t_texter	o_door;
// 	t_texter	c_door;
// 	t_texter	side;
// }	t_images;


typedef struct s_mlx
{
	void		*mlx;
	void		*img;
	void		*win;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_sprite	texters;
}	t_mlx;

typedef struct s_data
{
	t_mlx			*mlx;
	t_map			*map;
	t_table			*table;
	t_ray			*ray;
	t_position		*position;
	t_key			keystate;
	t_line_param	line_param;
	char			*gun[25];
	int				gun_x;
	int				gun_y;
	int				ray_w;
	int				ray_h;
	int				speed;
	int				cell_size;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e2;
	int				err;
}	t_data;

typedef struct s_book
{
	t_data			*data;
	t_map			*map_table;
	void			*mlx;//mlx_init
	void			*win;//mlx_new_window
	// t_coor			winsize;
	t_coor	*winsize;
	unsigned int	winfps;
	const char		*file;//file_name
	char			**file_content;
	// char			*elem_record[100];
	char			**elem_record;
	char			**map;

	
	t_coor			line_initial;
	int				line_steps;

	
	t_key			key;
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
int	map_reading(t_book *record);

//file_data_reading.c
int	file_data_reading(t_book *record);

//cb3d_printer.c
int map_print(char **db_arr);

//mlx_window.c
void	open_image(t_book *record);

//mlx_window.c
int    image_update(t_book *record);
void	ft_init_mlx(t_mlx *mlx);

//mlx_line.c
void    mlx_line_inc(float x_inc, float y_inc, t_book *record);
void    mlx_draw_line(int x0, int y0, int x1, int y1, t_book *record);

//mlx_hook_pack.c
void    hook_pack(t_book *record);

//raycasting.c
void	casting_rays(t_table *table, t_ray *rays, t_position position);

//init.c
void	create_trigonometric_tables(int narc, t_table *table, int i);
void	init_player_position(t_map *map, t_position *play_pos);
void	init_keystate(t_data *data);

//sprites.c
void	get_image(t_data *data);
void	ft_init_mlx(t_mlx *mlx);

//key_handling.c
int	keypress(int keycode, t_data *data);

#endif