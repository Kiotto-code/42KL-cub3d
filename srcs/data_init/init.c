/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:08:42 by yichan            #+#    #+#             */
/*   Updated: 2024/03/10 23:52:27 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	create_trigonometric_tables(int narc, t_table *table, int i)
{
	double	angle;
	double	ang_in;
	double	*tan_res;
	double	*sin_res;
	double	*cos_res;

	ang_in = ANG_IN_D * M_PI / 180.0;
	tan_res = malloc(sizeof(double) * narc);
	sin_res = malloc(sizeof(double) * narc);
	cos_res = malloc(sizeof(double) * narc);
	while (i < narc)
	{
		angle = i * ang_in;
		tan_res[i] = tan(angle);
		cos_res[i] = cos(angle);
		sin_res[i] = sin(angle);
		i++;
	}
	table->tan_table = tan_res;
	table->cos_table = cos_res;
	table->sin_table = sin_res;
}

void	init_keystate(t_data *data)
{
	data->keystate.w = 0;
	data->keystate.a = 0;
	data->keystate.s = 0;
	data->keystate.d = 0;
	data->keystate.left = 0;
	data->keystate.right = 0;
	data->keystate.click = 0;
	data->keystate.space = 0;
}

void	init_player_position(t_map *map, t_position *play_pos)
{
	int	player_view;

	play_pos->map = map;
	player_view = map->pv;
	play_pos->x_cell = map->px;
	play_pos->y_cell = map->py;
	play_pos->virtual_px = play_pos->x_cell * CELL_SIZE + CELL_SIZE / 2; //virtual position -> center of the cell
	play_pos->virtual_py = play_pos->y_cell * CELL_SIZE + CELL_SIZE / 2;
	if (player_view == 'N')
		play_pos->pov = N;
	else if (player_view == 'E')
		play_pos->pov = E;
	else if (player_view == 'S')
		play_pos->pov = S;
	else if (player_view == 'W')
		play_pos->pov = W;
}
