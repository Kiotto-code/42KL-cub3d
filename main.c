/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:50:00 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/17 21:36:17 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void record_init(t_book *record)
{
	record->map_table = (t_map *)malloc(sizeof(t_map));
	record->winsize = (t_coor *)malloc(sizeof(t_coor));
}

int main(int ac, char **av)
{
	t_data	data;
	t_book	record;

	// data.map = map_dup();

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
	
	init(&data, &record);
	(void)	ac;
	(void)	av;
}