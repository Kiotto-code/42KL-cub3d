/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:50:00 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/20 01:55:51 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void record_init(t_book *record)
{
	record->map_table = (t_map *)malloc(sizeof(t_map));
	record->winsize = (t_coords *)malloc(sizeof(t_coords));
}

static void	cub_map_parse_helper_setter(t_game *g,
		int i, int j, float degree)
{
	// printf("i: %d, j: %d\n", i, j);
	// (g->map.arr)[i][j] = '1';
	// printf("i>map.arr[i][j]: %c", g->map.arr[i][j]);
	// fflush(stdout);
	// g->map.arr[i][j] = '0';
	g->player.map_pos_x = j;
	g->player.map_pos_y = i;
	g->player.pos.x = TILE_SIZE * j + TILE_SIZE / 2;
	g->player.pos.y = TILE_SIZE * i + TILE_SIZE / 2;
	g->player.width = PLAYER_WIDTH;
	g->player.height = PLAYER_HEIGHT;
	g->player.angle = degree;
	g->player.speed = PLAYER_SPEED;
	g->player.rot_speed = g->constants.player_rotation_speed;
	(g->map.arr)[i][j] = '0';
}

static void record_player_struct(t_game *g, t_book *record)
{
	int i;
	int j;

	i = 0;
	// ft_print_arr(record->map, "check: record.map");
	// pause();
	while (record->map[i])
	{
		j = 0;
		while (record->map[i][j])
		{
			if (ft_strchr("NSWE", record->map[i][j]))
				break;
			j++;
		}
		if (ft_strchr("NSWE", record->map[i][j]))
			break;
		i++;
	}
	if (record->map[i] == NULL)
		ft_error("NO PLAYER FOUND", FAIL);
	cub_map_parse_helper_setter(g, i, j, -1);
	
}

int main(int ac, char **av)
{
	t_data	data;
	t_book	record;
	t_game	g;

	// data.map = map_dup();

	if (ac != 2)
		ft_error("WRONG ARGUMENT: ./cub3d <map.cub>\n", 2);
	if (ft_strcmp(ft_strend(av[1], 4), ".cub") != 0)
		ft_error("WRONG FILE EXTENSION", 2);
	record = (t_book){0};
	record.game= &g;
	record_init(&record);
	record.file = ft_strdup(av[1]);
	if (map_reading(&record) == FAIL)
		ft_error(RED"The map is not valid"RESET, FAIL);
	// ft_print_arr(record.map, "check: map:");
	// pause();
	if (file_data_recording(&record) == FAIL)
		ft_error(RED"file data recording failed"RESET, FAIL);

	// ft_print_arr(record.map, "check: record.map");
	
	g.map.arr = record.map;
	
	ft_print_arr(g.map.arr, BRIGHT_CYAN"check2: g.map.arr"RESET);
	// ft_print_arr(record.map, PURPLE"Check: "RESET);

	// g.map.arr[2][2] = 0;
	// pause();

	record_player_struct(&g, &record);
	ft_print_arr(record.map, PURPLE"Check: "RESET);
	// pause();
	
	init(&data, &record);
	(void)	ac;
	// (void)	av;
}