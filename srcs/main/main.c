/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:04:29 by yichan            #+#    #+#             */
/*   Updated: 2024/03/13 19:05:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// const void	*mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

void	data_initialize(t_data *data, t_table *table, t_position *position)
{
	create_trigonometric_tables(6480, table, 0);
	init_player_position(data->map, position);
}

// void	pre_exec(t_data *data, t_table *table, t_position *position)
// {
// 	create_trigonometric_tables(6480, table, 0);
// 	init_player_position(data->map, position);
// }

void	full_data(t_data *data, t_table *table,
	t_position *position, t_ray *ray)
{
	data->table = table;
	data->ray = ray;
	data->position = position;
	data->ray_h = 0;
}


void	run_game(t_book *record)
{
	t_table		table;
	t_position	position;
	t_ray		rays[RAY_NUM];
	t_data		data;

	record->data = &data;
	data.map = record->map_table;
	data.position = &position;
	data.table = &table;
	data.ray = rays;
	
	full_data(&data, &table, &position, rays);
	data_initialize(&data, &table, &position);
	ft_init_mlx(&data.mlx);
	get_image(&data);
	init_keystate(&data);
	weapon_install(&data);
	// start_game(&data);
}

void record_init(t_book *record)
{
	record->map_table = (t_map *)malloc(sizeof(t_map));
	record->winsize = (t_coor *)malloc(sizeof(t_coor));

}

int	main(int ac, char **av)
{
	t_book	record;

	if (ac != 2)
		ft_error("WRONG ARGUMENT: ./cub3d <map.cub>\n", 2);
	if (ft_strcmp(ft_strend(av[1], 4), ".cub") != 0)
		ft_error("WRONG FILE EXTENSION", 2);
	record = (t_book){0};
	record_init(&record);;
	record.file = ft_strdup(av[1]);
	if (map_reading(&record) == FAIL)
		ft_error(RED"The map is not valid"RESET, FAIL);
	// ft_print_arr(record.map, "check: map:");
	if (file_data_recording(&record) == FAIL)
		ft_error(RED"file data recording failed"RESET, FAIL);
	run_game(&record);
	
}
