/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:20:19 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 21:29:16 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_handling(t_data *data)
{
	t_sprite	*t;

	t = &data->mlx.texters;
	t->c_door.img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./wall_texters/code.xpm", &t->c_door.x, &t->c_door.y);
	t->c_door.addr = (int *)mlx_get_data_addr(t->c_door.img,
			&t->c_door.bits_per_pixel, &t->c_door.line_length,
			&t->c_door.endian);
	t->o_door.img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./wall_texters/ooo.xpm", &t->o_door.x, &t->o_door.y);
	t->o_door.addr = (int *)mlx_get_data_addr(t->o_door.img,
			&t->o_door.bits_per_pixel, &t->o_door.line_length,
			&t->o_door.endian);
	t->side.img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./wall_texters/side.xpm", &t->side.x, &t->side.y);
	t->side.addr = (int *)mlx_get_data_addr(t->side.img,
			&t->side.bits_per_pixel, &t->side.line_length, &t->side.endian);
}

void	get_image(t_data *data)
{
	t_sprite	*t;

	t = &data->mlx.texters;
	t->n_img.img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->map->meta_data[0], &t->n_img.x, &t->n_img.y);
	t->n_img.addr = (int *)mlx_get_data_addr(t->n_img.img,
			&t->n_img.bits_per_pixel, &t->n_img.line_length, &t->n_img.endian);
	t->s_img.img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->map->meta_data[1], &t->s_img.x, &t->s_img.y);
	t->s_img.addr = (int *)mlx_get_data_addr(t->s_img.img,
			&t->s_img.bits_per_pixel, &t->s_img.line_length, &t->s_img.endian);
	t->w_img.img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->map->meta_data[2], &t->w_img.x, &t->w_img.y);
	t->w_img.addr = (int *)mlx_get_data_addr(t->w_img.img,
			&t->w_img.bits_per_pixel, &t->w_img.line_length, &t->w_img.endian);
	t->e_img.img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->map->meta_data[3], &t->e_img.x, &t->e_img.y);
	t->e_img.addr = (int *)mlx_get_data_addr(t->e_img.img,
			&t->e_img.bits_per_pixel, &t->e_img.line_length, &t->e_img.endian);
	t->c_door.img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./wall_texters/code.xpm", &t->c_door.x, &t->c_door.y);
	t->c_door.addr = (int *)mlx_get_data_addr(t->c_door.img,
			&t->c_door.bits_per_pixel, &t->c_door.line_length,
			&t->c_door.endian);
	image_handling(data);
}