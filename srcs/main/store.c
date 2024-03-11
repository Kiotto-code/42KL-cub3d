/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:49:53 by yichan            #+#    #+#             */
/*   Updated: 2024/03/11 16:30:06 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_colors(t_map *map)
{
	char	**c;
	char	**f;
	int		i;

	i = 0;
	c = ft_split(map->meta_data[C], ',');
	f = ft_split(map->meta_data[F], ',');
	if (ft_tablen(c) != 3 || ft_tablen(f) != 3)
		return (0);
	while (i < 3)
	{
		if (!check_color(c[i], i) || !check_color(f[i], i))
			return (0);
		map->cl[i] = ft_atoi(c[i]);
		map->flr[i] = ft_atoi(f[i]);
		if (map->cl[i] < 0 || map->cl[i] > 255
			|| map->flr[i] < 0 || map->flr[i] > 255)
			return (0);
		i++;
	}
	map->int_c = rgbtolong(map->cl);
	map->int_f = rgbtolong(map->flr);
	f_tab(c);
	f_tab(f);
	return (1);
}


int	store(t_book *record)
{
	t_map	*map;

	map = record->map_table;
	map->map_tab = record->map;
	map->map_name = record->file;
	
	map->meta_data[0] = record->no;
	
	if (!get_colors(map))
		return (0);

	return (1);
}



// int	store(int fd, t_map *map)
// {
// 	char	*line;
// 	char	*map_string;

// 	map_string = NULL;
// 	if (!get_meta_data(fd, map))
// 		return (0);
// 	if (!get_colors(map))
// 		return (0);
// 	while (1)
// 	{
// 		line = gnl(fd);
// 		if (!line)
// 			break ;
// 		map_string = ft_strjoin(map_string, line);
// 		free(line);
// 	}
// 	if (!map_string)
// 		return (0);
// 	map_string = ft_map_clean(map_string);
// 	map->map_tab = ft_split(map_string, '\n');
// 	return (1);
// }