/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_endian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:22:03 by yichan            #+#    #+#             */
/*   Updated: 2024/01/16 02:43:15 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// int	mlx_mouse_move(void *win_ptr, int x, int y)
// {
// 	if (win_ptr && x >= 0 && y >= 0)
// 		SDL_WarpMouseInWindow(((t_mlx_window*)win_ptr)->window, x, y);
// 	return (0);
// }

// the num = 1 doesnt really matter as long as it is non zero;
int check_endian()
{
    int num;
    num = 1;

    return (*(char*)&num)?LITTLE_ENDIAN:BIG_ENDIAN;
}