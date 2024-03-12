/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:08:42 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 22:25:25 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	weapon_install(t_data *data)
{
	data->weapon[0] = "./gun/0.xpm";
	data->weapon[1] = "./gun/1.xpm";
	data->weapon[2] = "./gun/2.xpm";
	data->weapon[3] = "./gun/3.xpm";
	data->weapon[4] = "./gun/4.xpm";

}
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
	data->keystate = (t_key){0};
	data->line_param = (t_line_param){0};
}

void	init_player_position(t_map *map, t_position *play_pos)
{
	int	player_view;

	play_pos->map = map;
	player_view = map->pv;
	play_pos->x_cell = map->px;
	play_pos->y_cell = map->py;
	printf("y_cell: %d\n", play_pos->y_cell);
	printf("x_cell: %d\n", play_pos->x_cell);
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
