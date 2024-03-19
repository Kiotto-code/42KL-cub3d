/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:33:53 by yichan            #+#    #+#             */
/*   Updated: 2024/03/19 23:20:28 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// typedef struct s_wall_text_mapping
// {
// 	float			proj_height;
// 	int				wall_top_pixel;
// 	int				wall_bottom_pixel;
// 	float			cos_r;
// 	float			straight_dist;
// 	float			dist;
// 	t_iterators		text_offset;
// }	t_wall_text_mapping;

// void	draw_ceil(t_game *g, t_iterators it, t_wall_text_mapping *w_t_mapping)
// {
// 	int				i;
// 	t_coords		ceil;
// 	unsigned int	ceil_textcolor;
// 	int				text_ind;

// 	i = -1;
// 	while (++i < w_t_mapping->wall_top_pixel)
// 	{
// 		w_t_mapping->straight_dist = g->constants.screen_dist * PLAYER_HEIGHT
// 			/ (i - g->constants.half_win_height);
// 		w_t_mapping->dist = w_t_mapping->straight_dist / w_t_mapping->cos_r;
// 		ceil.x = g->player.pos.x - g->rays[it.i].cos_a * w_t_mapping->dist;
// 		ceil.y = g->player.pos.y - g->rays[it.i].sin_a * w_t_mapping->dist;
// 		w_t_mapping->text_offset.j = (int) ceil.x % TILE_SIZE;
// 		w_t_mapping->text_offset.i = (int) ceil.y % TILE_SIZE;
// 		text_ind = w_t_mapping->text_offset.i * TILE_SIZE
// 			+ w_t_mapping->text_offset.j;
// 		ceil_textcolor = ((unsigned int *) g->textures.ceil.addr)[text_ind]
// 			& INJECTED_COLOR;
// 		ft_mlx_put_px(g->mlx->mlx, it.i * g->constants.scale, i, ceil_textcolor);
// 	}
// }

// void	draw_floor(t_game *g, t_iterators it, t_wall_text_mapping *w_t_mapping)
// {
// 	int				i;
// 	t_coords		floor;
// 	unsigned int	floor_textcolor;
// 	int				text_ind;

// 	i = w_t_mapping->wall_bottom_pixel - 1;
// 	while (++i < WIN_H)
// 	{
// 		w_t_mapping->straight_dist = g->constants.screen_dist * PLAYER_HEIGHT
// 			/ (i - g->constants.half_win_height);
// 		w_t_mapping->dist = w_t_mapping->straight_dist / w_t_mapping->cos_r;
// 		floor.x = g->player.pos.x + g->rays[it.i].cos_a * w_t_mapping->dist;
// 		floor.y = g->player.pos.y + g->rays[it.i].sin_a * w_t_mapping->dist;
// 		w_t_mapping->text_offset.j = (int) floor.x % TILE_SIZE;
// 		w_t_mapping->text_offset.i = (int) floor.y % TILE_SIZE;
// 		text_ind = w_t_mapping->text_offset.i * TILE_SIZE
// 			+ w_t_mapping->text_offset.j;
// 		floor_textcolor = ((unsigned int *) g->textures.floor.addr)[text_ind]
// 			& INJECTED_COLOR;
// 		ft_mlx_put_px(g->mlx->mlx, it.i * g->constants.scale, i, floor_textcolor);
// 	}
// }

// void	draw_walls(t_game *g, t_iterators it, t_wall_text_mapping *w_t_mapping)
// {
// 	int				i;
// 	unsigned int	text_color;
// 	int				text_ind;

// 	if (g->rays[it.i].vertical_hit)
// 		w_t_mapping->text_offset.j = (int) g->rays[it.i].vert_inters.y;
// 	else
// 		w_t_mapping->text_offset.j = (int) g->rays[it.i].horz_inters.x;
// 	i = w_t_mapping->wall_top_pixel - 1;
// 	while (++i < w_t_mapping->wall_bottom_pixel)
// 	{
// 		w_t_mapping->text_offset.i = (i + (int) w_t_mapping->proj_height / 2
// 				- g->constants.half_win_height)
// 			* (TILE_SIZE / w_t_mapping->proj_height);
// 		text_ind = w_t_mapping->text_offset.i * TILE_SIZE
// 			+ w_t_mapping->text_offset.j;
// 		text_color = ((unsigned int *) get_texture(g, it.i).addr)[text_ind]
// 			& INJECTED_COLOR;
// 		ft_mlx_put_px(g->mlx->mlx, it.i * g->constants.scale, i, text_color);
// 	}
// }

// void	draw_world(t_game *g, t_iterators it, float ray_angle)
// {
// 	float				depth;
// 	t_wall_text_mapping	w_t_mapping;

// 	depth = (float) cos(g->player.angle - ray_angle) * g->rays[it.i].depth;
// 	w_t_mapping.proj_height = (TILE_SIZE / depth) * g->constants.screen_dist;
// 	w_t_mapping.wall_top_pixel = g->constants.half_win_height
// 		- ((int) w_t_mapping.proj_height) / 2;
// 	if (w_t_mapping.wall_top_pixel < 0)
// 		w_t_mapping.wall_top_pixel = 0;
// 	w_t_mapping.wall_bottom_pixel = g->constants.half_win_height
// 		+ ((int) w_t_mapping.proj_height) / 2;
// 	if (w_t_mapping.wall_bottom_pixel > WIN_H)
// 		w_t_mapping.wall_bottom_pixel = WIN_H;
// 	w_t_mapping.cos_r = cos(g->player.angle - ray_angle);
// 	draw_ceil(g, it, &w_t_mapping);
// 	draw_walls(g, it, &w_t_mapping);
// 	draw_floor(g, it, &w_t_mapping);
// 	g->buffer[it.i] = depth;
// }


unsigned int	get_textcolor(t_game *g, int type, t_iterators text_offset)
{
	int	ind;

	ind = (text_offset.i * TILE_SIZE) + text_offset.j;
	return (((unsigned int *) g->textures[type].addr)[ind]);
}

void	put_stripe(t_game *g, t_iterators it, t_iterators text_offset, int i)
{
	unsigned int	textcolor;

	if (g->rays[it.i].vertical_hit)
	{
		if (g->rays[it.i].horz_inters.x > g->player.pos.x)
			textcolor = get_textcolor(g, TEXT_E, text_offset);
		else
			textcolor = get_textcolor(g, TEXT_W, text_offset);
	}
	else
	{
		if (g->rays[it.i].vert_inters.y > g->player.pos.y)
			textcolor = get_textcolor(g, TEXT_S, text_offset);
		else
			textcolor = get_textcolor(g, TEXT_N, text_offset);
	}
	ft_mlx_put_px(g->mlx, it.i * g->constants.scale, i, textcolor);
}

void	draw_stripe(t_game *g, t_iterators it, int wall_top, int wall_bottom)
{
	t_iterators	text_offset;
	float		d;
	int			i;

	if (g->rays[it.i].vertical_hit)
		text_offset.j = (int) g->rays[it.i].vert_inters.y;
	else
		text_offset.j = (int) g->rays[it.i].horz_inters.x;
	d = TILE_SIZE / g->rays[it.i].proj_h;
	i = wall_top;
	while (i < wall_bottom)
	{
		text_offset.i = (i + (int) g->rays[it.i].proj_h / 2
				- g->constants.half_win_height) * d;
		put_stripe(g, it, text_offset, i);
		i++;
	}
}

// typedef struct s_draw_walls
// {
// 	int			i;
// 	int			wall_top_pixel;
// 	int			wall_bottom_pixel;
// 	float		depth;
// }	t_draw_walls;

// void	draw_walls(t_game *g, t_iterators it, float ray_angle)
// {
// 	t_draw_walls	s;

// 	s.depth = g->rays[it.i].depth * (float) cos(g->player.angle - ray_angle);
// 	g->rays[it.i].proj_h = (TILE_SIZE / s.depth) * g->constants.screen_dist;
// 	s.wall_top_pixel
// 		= g->constants.half_win_height - (int) g->rays[it.i].proj_h / 2;
// 	if (s.wall_top_pixel < 0)
// 		s.wall_top_pixel = 0;
// 	s.wall_bottom_pixel
// 		= g->constants.half_win_height + (int) g->rays[it.i].proj_h / 2;
// 	if (s.wall_bottom_pixel > WIN_H)
// 		s.wall_bottom_pixel = WIN_H;
// 	s.i = -1;
// 	while (++s.i < s.wall_top_pixel)
// 		ft_mlx_put_px(g->mlx,
// 			it.i * g->constants.scale, s.i, create_rgb(g->assets.ceiling));
// 	draw_stripe(g, it, s.wall_top_pixel, s.wall_bottom_pixel);
// 	s.i = s.wall_bottom_pixel - 1;
// 	while (++s.i < WIN_H)
// 		ft_mlx_put_px(g->mlx,
// 			it.i * g->constants.scale, s.i, create_rgb(g->assets.floor));
// }
