/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_pack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:17:01 by yichan            #+#    #+#             */
/*   Updated: 2024/01/19 17:57:35 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    shut_exit()
{
    printf("Thank you for playing this game!");
    exit(0);
}

static int handle_mouse(int x, int y, void *param)
{
    // Handle mouse movement
    printf("Mouse position: x=%d, y=%d\n", x, y);
    return 0;
}

// mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
void    hook_pack(t_book *record)
{
    // mlx_hook(record->mlx, )
    mlx_hook(record->win, 17, 0, &shut_exit, record);
	mlx_hook(record->win, 2, 1L << 0, &key_hook, record);
    mlx_hook(record->win, MotionNotify, PointerMotionMask, &handle_mouse, mlx)
}

void    key_hook()
{
    
}
