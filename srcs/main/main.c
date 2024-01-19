/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:04:29 by yichan            #+#    #+#             */
/*   Updated: 2024/01/18 10:55:00 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_book	record;

	if (ac != 2)
		ft_error("WRONG ARGUMENT: ./cub3d <map.cub>\n", 2);
	if (ft_strcmp(ft_strend(av[1], 4), ".cub") != 0)
		ft_error("WRONG FILE EXTENSION", 2);
	record = (t_book){0};
	record.file = ft_strdup(av[1]);
	if (map_file_checking(&record) == FAIL)
		ft_error(RED"The map is not valid"RESET, FAIL);
	record.mlx = mlx_init();
	open_image(&record);






	
	
	printf("\n\n"BG_BRIGHT_PURPLE"record.file_content HERE!!"RESET"\n\n");
	map_print(record.file_content);
	printf("\n\n"BG_BRIGHT_PURPLE"record.map HERE!!"RESET"\n\n");
	map_print(record.map);
}
