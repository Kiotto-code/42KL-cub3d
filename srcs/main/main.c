/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:04:29 by yichan            #+#    #+#             */
/*   Updated: 2024/03/11 10:35:57 by yichan           ###   ########.fr       */
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
	// t_mlx		mlx;

	// exit(0);
	record->data = &data;
	data.map = record->map;
	data.mlx = record->mlx;
	full_data(&data, &table, &position, rays);
	data_initialize(&data, &table, &position);
	ft_init_mlx(record->mlx);
	get_image(&data);
	init_keystate(&data);
	// open_image(record);
	// drawing(t_data *data);
}

// int	start_exec(t_map *map)
// {
// 	t_table		table;
// 	t_position	position;
// 	t_ray		rays[N_RAY];
// 	t_data		data;
// 	t_mlx		mlx;

// 	data.table = &table;
// 	data.ray = rays;
// 	data.position = &position;
// 	data.ray_h = 0;
// 	data.map = map;
// 	data.mlx = &mlx;
// 	pre_exec(&data, &table, &position);
// 	ft_init_mlx(&mlx);
// 	get_image(&data);
// 	init_keystate(&data);
// 	get_gun(&data);
// 	drawing(&data);
// 	hooking(&mlx, &data);
// 	return (1);
// }


int	main(int ac, char **av)
{
	t_book	record;

	if (ac != 2)
		ft_error("WRONG ARGUMENT: ./cub3d <map.cub>\n", 2);
	if (ft_strcmp(ft_strend(av[1], 4), ".cub") != 0)
		ft_error("WRONG FILE EXTENSION", 2);
	record = (t_book){0};
	record.file = ft_strdup(av[1]);
	if (map_reading(&record) == FAIL)
		ft_error(RED"The map is not valid"RESET, FAIL);
	// record.mlx = mlx_init();
	run_game(&record);
	
	// open_image(&record);
	
	// printf("\n\n"BG_BRIGHT_PURPLE"record.file_content HERE!!"RESET"\n\n");
	// map_print(record.file_content);
	// printf("\n\n"BG_BRIGHT_PURPLE"record.map HERE!!"RESET"\n\n");
	// map_print(record.map);
	// mlx_destroy_display(record.mlx);
}
