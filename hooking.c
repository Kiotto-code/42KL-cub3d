/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:27:32 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/20 01:37:25 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		printf("game ended\n");
		exit (0);
	}
	if (keycode == KEY_W)
		data->player->walk_direction = -1;
	else if (keycode == KEY_S)
		data->player->walk_direction = 1;
	else if (keycode == KEY_A)
		data->player->turn_direction = -1;
	else if (keycode == KEY_D)
		data->player->turn_direction = 1;
	else if (keycode == ARROW_LEFT)
		data->player->rotation_direction = -1;
	else if (keycode == ARROW_RIGHT)
		data->player->rotation_direction = 1;
	else if (keycode == SPACE)
		data->keystate->space = 1;
	return (0);
}

int	keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->player->walk_direction = 0;
	else if (keycode == KEY_S)
		data->player->walk_direction = 0;
	else if (keycode == KEY_A)
		data->player->turn_direction = 0;
	else if (keycode == KEY_D)
		data->player->turn_direction = 0;
	else if (keycode == ARROW_LEFT)
		data->player->rotation_direction = 0;
	else if (keycode == ARROW_RIGHT)
		data->player->rotation_direction = 0;
	else if (keycode == SPACE)
		data->keystate->space = 0;
	return (0);
}

void	update(t_book *record)
{
	t_game			*g;
	static float	ticks_last_frame = 0.0;

	// if (ticks_last_frame < 0.5)
	// 	ticks_last_frame = (float) current_time_ms();
	// while ((float) current_time_ms()
	// 	- (ticks_last_frame + g->constants.frame_rate) < 0)
	// 	;
	g = record->game;
	g->delta_time = 0.04;
	ticks_last_frame = 0.03;
	// ticks_last_frame = (float)current_time_ms();
	// player_movement(g);
	raycast(g);
	ft_color_win(record->data, record->data->mlx, 0); // colours green for the whole map
	put_map(record->data); // puts minimap
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
// 	player_movement(g);
// 	raycast(g);
// }

int	render(t_book *record)
{
	static unsigned int	frames = 0;
	static unsigned int	last_fps = FPS;
	clock_t				elapsed_ticks;
	t_game				*g;

	g = record->game;
	g->frame.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->frame.addr = mlx_get_data_addr(g->frame.img, &g->frame.bpp,
			&g->frame.line_length, &g->frame.endian);
	frames++;
	elapsed_ticks = clock() - g->start_time;
	if (elapsed_ticks >= CLOCKS_PER_SEC)
	{
		last_fps = frames;
		frames = 0;
		g->start_time = clock();
	}
	update(record);
	mlx_put_image_to_window(g->mlx, g->win.img, g->frame.img, 0, 0);
	mlx_destroy_image(g->mlx, g->frame.img);
	return (RETURN_SUCCESS);
}
// int	render(t_book *record)
// {
// 	static unsigned int	frames = 0;
// 	static unsigned int	last_fps = FPS;
// 	clock_t				elapsed_ticks;
// 	t_game				*g;

// 	g = record->game;
// 	g->frame.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
// 	g->frame.addr = mlx_get_data_addr(g->frame.img, &g->frame.bpp,
// 			&g->frame.line_length, &g->frame.endian);
// 	frames++;
// 	elapsed_ticks = clock() - g->start_time;
// 	if (elapsed_ticks >= CLOCKS_PER_SEC)
// 	{
// 		last_fps = frames;
// 		frames = 0;
// 		g->start_time = clock();
// 	}
// 	update(g);
// 	mlx_put_image_to_window(g->mlx, g->win.img, g->frame.img, 0, 0);
// 	mlx_destroy_image(g->mlx, g->frame.img);
// 	return (RETURN_SUCCESS);
// }
static int handle_mouse_motion(int x, int y, void *param) {
    // Handle mouse motion
    // printf("Mouse motion: x=%d, y=%d\n", x, y);
	(void) param;
	(void) x;
	(void) y;
    return (0);
}

int	shut_exit(void)
{
	ft_putendl_fd("THANK YOU FOR PLAYING THIS GAME !", 1);
	exit(0);
	return (0);
}

void	hooking(t_image *mlx, t_book *record)
{
	// mlx_hook(mlx->win, 02, 00, &keypress, record->data);
	// mlx_hook(mlx->win, 03, 0L, &keyrelease, record->data);
	// mlx_loop_hook(mlx->mlx, &render, record);
	// mlx_loop(mlx->mlx);

	mlx_hook(mlx->win, DestroyNotify, NoEventMask, &shut_exit, record);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, &keypress, record);
	mlx_hook(mlx->win, KeyRelease, KeyPressMask, &keyrelease, record);
	mlx_hook(mlx->win, MotionNotify, NoEventMask, &handle_mouse_motion, record);
    // mlx_hook(mlx->win, MotionNotify, PointerMotionMask, &handle_mouse_motion, record);
	mlx_loop_hook(mlx->mlx, &render, record);
	mlx_loop(mlx->mlx);
}

