/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:09:17 by yichan            #+#    #+#             */
/*   Updated: 2024/01/24 17:11:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    image_update(t_book *record)
{
    // mlx_draw_line(0,0,400,500,record);
    (void) record;
    return (0);
};

//so_long image_update
// int	image_update(t_book *record)
// {
// 	record->winfps++;
// 	mlx_clear_window(record->mlx, record->win);
// 	project_image(record);
// 	sl_player_anime(record);
// 	if (record->data.enemy > 0)
// 		sl_enemy_anime(record);
// 	string_put_mod(record);
// 	if (record->winfps >= FPS)
// 		record->winfps = 0;
// 	data_update(record);
// 	return (0);
// }