/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_pack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:57:12 by yichan            #+#    #+#             */
/*   Updated: 2024/01/26 23:42:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	shut_exit(void)
{
	ft_putendl_fd("THANK YOU FOR PLAYING THIS GAME !", 1);
	exit(0);
	return (0);
}

// static int	key_release(const int keycode, t_book *record)
// {}

static int handle_mouse_motion(int x, int y, void *param) {
    // Handle mouse motion
    printf("Mouse motion: x=%d, y=%d\n", x, y);
	(void) param;
    return (0);
}

static int	key_press(const int keycode, t_book *record)
{
	if (keycode == KEY_W)
		record->key.w = KEY_W;
	if (keycode == KEY_A)
		record->key.a = KEY_A;
	if (keycode == KEY_S)
		record->key.s = KEY_S;
	if (keycode == KEY_D)
		record->key.d = KEY_D;
	// if (keycode == KEY)

	return (0);
}

int handle_key_press(int keycode, void *param) {
    // printf("Key pressed: %d\n", keycode);
    printf("Key pressed: %d\n", keycode);
    if (keycode == kVK_Escape)
		shut_exit();
	(void) param;
    return 0;
}

void    hook_pack(t_book *record)
{
    mlx_hook(record->win, DestroyNotify, NoEventMask, &shut_exit, record);
	mlx_hook(record->win, KeyPress, KeyPressMask, &key_press, record);
	mlx_hook(record->win, KeyPress, KeyPressMask, &handle_key_press, record);
	mlx_hook(record->win, MotionNotify, NoEventMask, &handle_mouse_motion, record->mlx);
    mlx_hook(record->win, MotionNotify, PointerMotionMask, &handle_mouse_motion, record->mlx);
}