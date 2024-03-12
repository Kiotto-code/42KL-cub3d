/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:14:17 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 22:16:59 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	start_game(t_data *data)
// {
// 	data->ray = (t_ray *)malloc(sizeof(t_ray) * RAY_NUM);
// 	if (data->keystate.esc)
// 	{
// 		printf("game finished hope you enjoy it ;)\n");
// 		exit(0);
// 	}
// 	casting_rays(data->table, data->ray, *data->position);
// 	ft_color_win(data, data->mlx, data->ray_h);
// 	ft_3d(data);
// 	put_map(data);
// 	put_gun(data);
// }