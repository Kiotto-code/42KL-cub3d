/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:20:49 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/20 01:56:38 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

bool	check_if_wall(int content)
{
	return (content == 1);
}

void	find_hor_steps(t_game *game, int i, t_coords *dist, float *depth)
{
	if (game->rays[i].sin_a > 0)
	{
		game->rays[i].horz_inters.y = (game->player.map_pos_y + 1) * CELL_SIZE;
		dist->y = CELL_SIZE;
	}
	else
	{
		game->rays[i].horz_inters.y = game->player.map_pos_y * CELL_SIZE - 0.0001;
		dist->y = -CELL_SIZE;
	}
	game->rays[i].depth_horz = game->rays[i].horz_inters.y - game->player.pos.y;
	game->rays[i].depth_horz /= game->rays[i].sin_a;
	game->rays[i].horz_inters.x = game->rays[i].depth_horz * game->rays[i].cos_a;
	game->rays[i].horz_inters.x += game->player.pos.x;
	*depth = dist->y / game->rays[i].sin_a;
	dist->x = *depth * game->rays[i].cos_a;
}

void	find_vert_steps(t_game *game, int i, t_coords *dist, float *depth)
{
	if (game->rays[i].cos_a > 0)
	{
		game->rays[i].vert_inters.x = (game->player.map_pos_x + 1) * CELL_SIZE;
		dist->x = CELL_SIZE;
	}
	else
	{
		game->rays[i].vert_inters.x = game->player.map_pos_x * CELL_SIZE - 0.0001;
		dist->x = -CELL_SIZE;
	}
	game->rays[i].depth_vert = game->rays[i].vert_inters.x - game->player.pos.x;
	game->rays[i].depth_vert /= game->rays[i].cos_a;
	game->rays[i].vert_inters.y = game->rays[i].depth_vert * game->rays[i].sin_a;
	game->rays[i].vert_inters.y += game->player.pos.y;
	*depth = dist->x / game->rays[i].cos_a;
	dist->y = *depth * game->rays[i].sin_a;
}

void	check_vert_inters(t_game *g, int i, t_coords dist, float depth)
{
	t_iterators	vert_tile;
	int			j;

	j = -1;
	while (++j < MAX_DEPTH)
	{
		vert_tile.j = abs((int)(g->rays[i].vert_inters.x / TILE_SIZE));
		vert_tile.i = abs((int)(g->rays[i].vert_inters.y / TILE_SIZE));
		if (vert_tile.i >= g->map.height || vert_tile.j >= g->map.width)
			break ;
		if (check_if_wall(g->map.arr[vert_tile.i][vert_tile.j]))
		{
			g->rays[i].vert_wall_content = g->map.arr[vert_tile.i][vert_tile.j];
			break ;
		}
		g->rays[i].vert_inters.x += dist.x;
		g->rays[i].vert_inters.y += dist.y;
		g->rays[i].depth_vert += depth;
	}
}

void	check_horz_inters(t_game *g, int i, t_coords dist, float depth)
{
	t_iterators	horz_tile;
	int			j;

	j = -1;
	while (++j < MAX_DEPTH)
	{
		horz_tile.j = abs((int)(g->rays[i].horz_inters.x / TILE_SIZE));
		horz_tile.i = abs((int)(g->rays[i].horz_inters.y / TILE_SIZE));
		if (horz_tile.i >= g->map.height || horz_tile.j >= g->map.width)
			break ;
		if (check_if_wall(g->map.arr[horz_tile.i][horz_tile.j]))
		{
			g->rays[i].horz_wall_content = g->map.arr[horz_tile.i][horz_tile.j];
			break ;
		}
		g->rays[i].horz_inters.x += dist.x;
		g->rays[i].horz_inters.y += dist.y;
		g->rays[i].depth_horz += depth;
	}
}

void	final_inters(t_game *game, int i)
{
	if (game->rays[i].depth_vert < game->rays[i].depth_horz)
	{
		game->rays[i].vert_inters.y = fmod(game->rays[i].vert_inters.y, CELL_SIZE);
		game->rays[i].depth = game->rays[i].depth_vert;
		game->rays[i].wall_hit = game->rays[i].vert_inters;
		game->rays[i].content_hit = game->rays[i].vert_wall_content;
		game->rays[i].vertical_hit = true;
	}
	else
	{
		game->rays[i].horz_inters.x = fmod(game->rays[i].horz_inters.x, CELL_SIZE);
		game->rays[i].depth = game->rays[i].depth_horz;
		game->rays[i].wall_hit = game->rays[i].horz_inters;
		game->rays[i].content_hit = game->rays[i].horz_wall_content;
		game->rays[i].vertical_hit = false;
	}
}

// void	raycast(t_data *data)
// {
// 	t_coords	dist;
// 	float		delta_depth;	
// 	float		ray_angle;
// 	(void)dist;
// 	(void)delta_depth;
// 	int			i;
	
// 	ray_angle = game->player.angle - game->constant->half_fov + 0.0001;
// 	i = -1;
// 	while (++i < N_RAY) // there will be total of 1080 rays
// 	{
// 		game->rays[i].angle = ray_angle;
// 		game->rays[i].sin_a = sin(ray_angle);
// 		game->rays[i].cos_a = cos(ray_angle);

// 		printf(YELLOW);
// 		printf("%i sin ray = %f", i , game->rays[i].sin_a);
// 		printf("%i cos ray = %f", i , game->rays[i].cos_a);
// 		printf(RESET);
		
// 		find_hor_steps(data, i, &dist, &delta_depth);
// 		check_horz_inters(data, i, dist, delta_depth);
// 		find_vert_steps(data, i, &dist, &delta_depth);
// 		check_vert_inters(data, i, dist, delta_depth);
// 		final_inters(data, i);

// 		draw_world(data, i, ray_angle);
// 		// draw_walls(data, it, ray_angle);
// 		ray_angle += game->constant->delta_angle; // each ray will add 0.0555555
// 	}
// }

void	raycast(t_game *g)
{
	t_coords	dist;
	float		delta_depth;
	float		ray_angle;
	int			it;
	t_iterators iter;

	g->player.map_pos_x = (int)(g->player.pos.x / TILE_SIZE);
	g->player.map_pos_y = (int)(g->player.pos.y / TILE_SIZE);
	ray_angle = g->player.angle - g->constants.half_fov + 0.0001;
	it = -1;
	while (++it < NUM_RAYS)
	{
		g->rays[it].angle = ray_angle;
		g->rays[it].sin_a = sin(ray_angle);
		g->rays[it].cos_a = cos(ray_angle);

		printf(YELLOW);
		printf("%i sin ray = %f", it , g->rays[it].sin_a);
		printf("%i cos ray = %f", it , g->rays[it].cos_a);
		printf(RESET);

		find_hor_steps(g, it, &dist, &delta_depth);
		check_horz_inters(g, it, dist, delta_depth);
		find_vert_steps(g, it, &dist, &delta_depth);
		check_vert_inters(g, it, dist, delta_depth);
		final_inters(g, it);
		iter.i = it;
		// draw_walls(g, iter, ray_angle);
		ray_angle += g->constants.delta_angle;
	}
}


// void	update(t_game *g)
// {
// 	static float	ticks_last_frame = 0.0;

// 	if (ticks_last_frame < 0.5)
// 		ticks_last_frame = (float) current_time_ms();
// 	while ((float) current_time_ms()
// 		- (ticks_last_frame + g->constants.frame_rate) < 0)
// 		;
// 	g->delta_time = (float)(current_time_ms() - ticks_last_frame) / 1000.0f;
// 	ticks_last_frame = (float)current_time_ms();
// 	// player_movement(g);
// 	raycast(g);
// }
