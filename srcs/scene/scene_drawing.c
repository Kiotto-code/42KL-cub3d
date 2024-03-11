/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:14:17 by yichan            #+#    #+#             */
/*   Updated: 2024/03/10 23:05:46 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing(t_data *data)
{
	if (data->keystate.esc)
	{
		ft_print("game finished hope you enjoy it ;)\n");
		exit(0);
	}
	casting_rays(data->table, data->ray, *data->position);
	ft_color_win(data, data->mlx, data->ray_h);
	ft_3d(data);
	put_map(data);
	put_gun(data);
}