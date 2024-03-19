/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 01:16:49 by absalhi           #+#    #+#             */
/*   Updated: 2024/03/19 18:06:43 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

unsigned int	create_rgb(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

// t_image	get_texture(t_game *g, int ind)
// {
// 	if (g->rays[ind].content_hit >= 1 && g->rays[ind].content_hit <= 5)
// 		return (g->textures.walls[g->rays[ind].content_hit - 1]);
// 	return (g->textures.walls[0]);
// }
