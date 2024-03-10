/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:44:58 by yichan            #+#    #+#             */
/*   Updated: 2024/03/10 01:02:54 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "cub3D");
	mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

// static void	toggle_mouse(t_ctx *ctx)
// {
// 	if (ctx->key.mouse)
// 	{
// 		mlx_mouse_show();
// 		ctx->key.mouse = 0;
// 	}
// 	else
// 	{
// 		mlx_mouse_hide();
// 		mlx_mouse_move(ctx->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
// 		ctx->key.mouse = 1;
// 	}
// }

// int	shut_exit(void)
// {
// 	ft_putendl_fd("THANK YOU FOR PLAYING THIS GAME !", 1);
// 	exit(0);
// 	return (0);
// }

// // static int	key_release(const int keycode, t_book *record)
// // {}

// static int handle_mouse_motion(int x, int y, void *param) {
//     // Handle mouse motion
//     printf("Mouse motion: x=%d, y=%d\n", x, y);
// 	(void) param;
//     return (0);
// }

// static int	key_press(const int keycode, t_book *record)
// {
// 	if (keycode == KEY_W)
// 		record->key->a = KEY_W;
// 	if (keycode == KEY_A)
// 		record->key->a = KEY_A;
// 	if (keycode == KEY_S)
// 		record->key->a = KEY_S;
// 	if (keycode == KEY_D)
// 		record->key->a = KEY_D;
// 	// if (keycode == KEY)

// 	return (0);
// }

// int handle_key_press(int keycode, void *param) {
//     // printf("Key pressed: %d\n", keycode);
//     printf("Key pressed: %d\n", keycode);
//     if (keycode == kVK_Escape)
// 		shut_exit();
// 	(void) param;
//     return 0;
// }

// void    hook_pack(t_book *record)
// {
//     mlx_hook(record->win, DestroyNotify, NoEventMask, &shut_exit, record);
// 	mlx_hook(record->win, KeyPress, KeyPressMask, &key_press, record);
// 	mlx_hook(record->win, KeyPress, KeyPressMask, &handle_key_press, record);
// 	mlx_hook(record->win, MotionNotify, NoEventMask, &handle_mouse_motion, record->mlx);
//     mlx_hook(record->win, MotionNotify, PointerMotionMask, &handle_mouse_motion, record->mlx);
// }

void	open_image(t_book *record)
{
	record->win = mlx_new_window(record->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3d!");
	if (record->win == NULL)
	{
		free(record->win);
		ft_error("mlx_new_window not open", 1);
	}
	// record->win = mlx_new_window(record->mlx, record->mapsize.x * INTERVAL,
	// 		record->mapsize.y * INTERVAL, "So_long!");
	// insert_sprites(record);
	mlx_do_sync(record->mlx); // Make sure the events are synchronized
	// mlx_hook(record->win, DestroyNotify, NoEventMask, &shut_exit, record);
	// mlx_hook(record->win, KeyPress, KeyPressMask, &key_press, record);
	// mlx_hook(record->win, KeyPress, KeyPressMask, &handle_key_press, record);
	// mlx_hook(record->win, MotionNotify, NoEventMask, &handle_mouse_motion, record->mlx);
    // mlx_hook(record->win, MotionNotify, PointerMotionMask, &handle_mouse_motion, record->mlx);
	hook_pack(record);
	mlx_draw_line(0,0,400,500,record);
	mlx_loop_hook(record->mlx, &image_update, record);
	mlx_loop(record->mlx);
}