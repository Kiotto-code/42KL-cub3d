#pragma once

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <math.h>

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <time.h>
# include <mlx.h>
# include <signal.h>
# include <stdbool.h>
# include <stdint.h>

# include "color.h"
# include "libft/includes/libft.h"
# include "enum.h"
# include "macro.h"
# include "struct.h"


# define WIN_W 1080 // screen width
# define WIN_H 520 // screen height
# define CELL_SIZE 500
# define RAY_ANGLE_DIFF 0.05555555555 // each ray distance within player pov (60 / 1080)
# define MAX_DEPTH 100
# define N_RAY NUM_RAYS // number of ray being casted


# define N_OF_SOUNDS 11

# define N_OF_OBJECTS 19
# define OBJECTS_MAX_FRAME 9

# define N_OF_WEAPONS 2
# define WEAPONS_MAX_FRAME 6

# define WEAPON_KNIFE_FRAMES 4
# define WEAPON_SHOTGUN_FRAMES 6

# define PLAYER 99



typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_assets
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_color	floor;
	t_color	ceiling;
}	t_assets;


// enum e_trigo 
// {
// 	SIN = 1,
// 	COS = 2,
// 	TAN = 3
// };
// # define ERROR "\033[1;31m"
// # define GREEN "\033[0;32m" 
// # define YELLOW "\033[0;33m"
// # define RESET "\033[0m"

enum
{
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_W = 13,
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	SPACE = 49
};


// typedef struct s_coor
// {
// 	int				y;
// 	int				x;
// }	t_coords;

typedef struct s_iterators
{
	int	i;
	int	j;
	int	k;
	int	l;
}	t_iterators;


typedef struct s_keystate
{
	int	tir;
	int	w;
	int	a;
	int	s;
	int	d;
	int	r;
	int	l;
	int	space;
	int	esc;
}	t_keystate;

typedef struct s_image
{
	void		*mlx;
	void		*img; //img
	void		*win;
	void		*addr;
	int			bpp; //bits per pixel
	int			line_length;
	int			endian;
	// t_texters	texters;
}	t_image; //t_image
// typedef struct s_image
// {
// 	void		*mlx;
// 	void		*img; //img
// 	void		*win;
// 	void		*addr;
// 	int			bits_per_pixel;
// 	int			line_length;
// 	int			endian;
// 	// t_texters	texters;
// }	t_image; //t_image

// typedef struct s_position
// {
// 	int		x_cell;
// 	int		y_cell;
// 	double	virtual_px;
// 	double	virtual_py;
// 	double	pov;
// 	char	**map;
// }	t_position;

typedef struct s_coords
{
	float	x;
	float	y;
}	t_coords;


typedef struct s_ray
{
	t_coords	wall_hit;
	float		angle;
	float		depth;
	bool		vertical_hit;
	int			content_hit;
	float		sin_a;
	float		cos_a;
	t_coords	horz_inters;
	t_coords	vert_inters;
	float		depth_horz;
	float		depth_vert;
	float		horz_wall_content;
	float		vert_wall_content;
	float		proj_h;
}	t_ray;

typedef struct s_player
{
	// actual player postion in pixel
	t_coords	pos;
	// map player position
	int			map_pos_x;
	int			map_pos_y;
	int			width;
	int			height;
	// player pov
	float		angle;
	float		speed;
	float		rot_speed;
	int			turn_direction; // Keys A D ARROW_LEFT ARROW_RIGHT
	int			walk_direction; // Keys W S
	int			rotation_direction;
	char		**map;
}	t_player;


// typedef struct s_player
// {
// 	t_coords	pos;
// 	t_coords	map_pos;
// 	int			width;
// 	int			height;
// 	float		angle;
// 	float		speed;
// 	float		rot_speed;
// 	int			turn_direction;
// 	int			walk_direction;
// 	int			rotation_direction;
// }	t_player;

typedef struct s_constants
{
	float	frame_rate;
	float	half_win_width;
	float	half_win_height;
	float	fov;
	float	half_fov;
	float	screen_dist;
	int		num_rays;
	float	half_num_rays;
	float	scale;
	float	delta_angle;
	float	player_rotation_speed;
	float	tau;
}	t_constants;


typedef struct s_map
{
	const char		*map_name;
	int				fd;
	char			**arr; //without the player
	// int		**arr;
	int				width;
	int				height;
	int				map_h;
	int				map_w;
	int				map_vh;
	int				map_vw; //map_tab = map table, map_name = map name, map_h = map height, map_w = map width, map_vh = map virtual height, map_vw = map virtual width
	int				pn;
	int				px;
	int				py; 
	int				pv; //pn = player number, px = player x, py = player y, pv = player pov
	char			*meta_data[7]; //meta_data[0] = NO, meta_data[1] = SO, meta_data[2] = WE, meta_data[3] = EA, meta_data[4] = F, meta_data[5] = C
	int				f_color[3];
	int				c_color[3]; //flr and cl are the same as int_f and int_c but in decimal
	unsigned long	int_f;
	unsigned long	int_c; //int_f and int_c are the same as flr and cl but in hex
}	t_map;



// typedef struct s_map
// {
// 	char	*path;
// 	int		fd;
// 	int		**arr;
// 	int		width;
// 	int		height;
// }	t_map;

typedef struct s_object
{
	int			infos[6];
	int			type;
	int			state;
	t_coords	pos;
	int			frame;
	bool		animating;
	clock_t		last_time;
	float		dist;
	bool		display;
	bool		visible;
}	t_object;


typedef struct s_data
{
	t_image			*mlx;
	t_keystate		*keystate;
	t_player		*player;
	t_ray			*rays;
	t_constants		*constant;
	char			**map; // actual map
	// int				map_w; // set map height and width
	// int				map_h;
	int				cell_size;

}	t_data;

// typedef struct s_book
// {
// 	t_data			*data;
// 	t_game			*game;
// 	void			*win;//mlx_new_window
// 	unsigned int	winfps;
// 	const char		*file;//file_name
// 	char			**file_content;
// 	char			**elem_record;
// 	char			**map;
// 	t_coords		*winsize;		//dynamic allocation
// 	t_map			*map_table;		//dynamic allocation
// 	t_coords		line_initial;
// 	int				line_steps;

	
// 	t_keystate			key;
// }	t_book;

// typedef struct s_window
// {
// 	void	*img;
// 	int		width;
// 	int		heigt;
// }	t_window;

typedef struct s_error
{
	char	*message;
	int		code;
}	t_error;

// typedef struct s_color
// {
// 	int	r;
// 	int	g;
// 	int	b;
// }	t_color;

typedef struct s_tips
{
	bool		open_door;
	bool		game_over;
}	t_tips;

typedef struct s_mouse
{
	bool		left;
	bool		right;
	bool		enabled;
	int			x;
	float		angle;
}	t_mouse;

// typedef struct s_weapon
// {
// 	int			type;
// 	t_image		image[N_OF_WEAPONS][WEAPONS_MAX_FRAME];
// 	char		*path[N_OF_WEAPONS][WEAPONS_MAX_FRAME];
// 	t_iterators	dimension[N_OF_WEAPONS];
// 	int			frame;
// 	int			n_of_frames[N_OF_WEAPONS];
// 	size_t		frame_rate[N_OF_WEAPONS];
// 	clock_t		last_time;
// 	int			animating;
// 	t_coords	pos;
// 	int			damage[N_OF_WEAPONS];
// 	float		range[N_OF_WEAPONS];
// 	int			sound[N_OF_WEAPONS];
// 	bool		collected[N_OF_WEAPONS];
// }	t_weapon;


typedef struct s_texture
{
	t_image		sides[4];
	t_image		health_bar[6];
	t_image		walls[5];
	t_image		floor;
	t_image		ceil;
	t_image		splash[2];
	t_image		game_over;
	t_image		digits[10];
	// t_weapon	weapon;
	t_image		object_image[N_OF_OBJECTS][OBJECTS_MAX_FRAME];
	char		*object_path[N_OF_OBJECTS][OBJECTS_MAX_FRAME];
	t_iterators	object_dimension[N_OF_OBJECTS];
	int			object_n_of_frames[N_OF_OBJECTS];
	size_t		object_frame_rate[N_OF_OBJECTS];
	clock_t		object_last_time[N_OF_OBJECTS];
	float		object_scale[N_OF_OBJECTS];
}	t_texture;

// typedef struct s_game
// {
// 	void		*mlx;
// 	// t_window	win;
// 	t_map		map;
// 	t_error		error;
// 	// t_parsing	parsing;
// 	// t_assets	assets;
// 	t_ray		*rays;
// 	t_player	player;
// 	t_image		frame;
// 	clock_t		start_time;
// 	float		delta_time;
// 	bool		paused;
// 	bool		freeze;
// 	bool		game_over;
// 	// t_alloc		allocated;
// 	t_tips		tips;
// 	t_texture	textures;
// 	t_object	*objects;
// 	int			objects_count;
// 	t_mouse		mouse;
// 	// t_sound		sound[N_OF_SOUNDS];
// 	// t_pid		pid;
// 	t_constants	constants;
// 	float		*buffer;
// 	bool		display_map;
// }	t_game;

typedef struct s_window
{
	void	*img;
	int		width;
	int		height;
}	t_window;

// typedef struct s_game
// {
// 	void		*mlx;
// 	t_window	win;
// 	t_map		map;
// 	t_error		error;
// 	// t_parsing	parsing;
// 	t_assets	assets;
// 	t_ray		*rays;
// 	t_player	player;
// 	t_image		frame;
// 	clock_t		start_time;
// 	float		delta_time;
// 	bool		paused;
// 	bool		freeze;
// 	bool		game_over;
// 	// t_alloc		allocated;
// 	t_image		textures[4];
// 	t_constants	constants;
// }	t_game;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_map		map;
	t_error		error;
	// t_parsing	parsing;
	t_assets	assets;
	t_ray		*rays;
	t_player	player;
	t_image		frame;
	clock_t		start_time;
	float		delta_time;
	bool		paused;
	bool		freeze;
	bool		game_over;
	// t_alloc		allocated;
	t_image		textures[4];
	t_constants	constants;
}	t_game;

typedef struct s_book
{
	t_data			*data;
	t_game			*game;
	void			*win;//mlx_new_window
	unsigned int	winfps;
	const char		*file;//file_name
	char			**file_content;
	char			**elem_record;
	char			**map;
	t_coords		*winsize;		//dynamic allocation
	t_map			*map_table;		//dynamic allocation
	t_coords		line_initial;
	int				line_steps;

	
	t_keystate			key;
}	t_book;

// libft.c (tools for cub3d)
// int	ft_strchr(char c, char *s);
// int	ft_is_whitespace(int c);

// test.c (for testing tools)
// char**map_dup();
void print_img(t_data *data);
void print_arr(char **arr);

//init.c 
void init(t_data *data, t_book *record);

//keyboard.c
void	hooking(t_image *mlx, t_book *record)
;
// drawing.c
void drawing(t_data *data);

// raycast.c
void	raycast(t_game *g);
void	draw_walls(t_game *g, t_iterators it, float ray_angle);

// map_validity.c
int	all_wall(char *str);
int	ends_wall(char **map);
int	map_valid_wall_surround(t_book *record);
int	map_reading(t_book *record);

// map_find.c
int	get_player_view(t_book *record, t_map *map_table);
int file_data_recording(t_book *record);
int	check_map_holes(char **map);
int	file_data_reading(t_book *record);

// store.c
int	get_colors(t_map *map);
int	store(t_book *record);

//drawing,c
void	ft_mlx_put_px(t_image *mlx, int x, int y, unsigned int color);
void	ft_color_win(t_data *data, t_image *mlx, int ray_h);
void	put_map(t_data *data);

//utils.c
unsigned int	create_rgb(t_color color);
// t_image	get_texture(t_game *g, int ind);·
