/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:58:42 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 17:14:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	casting_rays(t_table *table, t_ray *rays, t_position position)
// {
// 	int	i;

// 	i = 0;
// 	while (i < RAY_NUM)
// 	{
// 		rays[i].ray_pov = calcul_ray_pov(position, i);
// 		rays[i].index = calcul_ray_angle(&rays[i], rays[i].ray_pov);
// 		calcul_first_vertical(table, &rays[i], position);
// 		calcul_first_horizontal(table, &rays[i], position);
// 		rays[i].door = 0;
// 		rays[i].h_hit = 0;
// 		rays[i].v_hit = 0;
// 		rays[i].h_skip = 0;
// 		rays[i].v_skip = 0;
// 		rays[i].first = 0;
// 		send_ray(table, &rays[i], position);
// 		i++;
// 	}
// }