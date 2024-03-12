/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:49:53 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 21:08:39 by yichan           ###   ########.fr       */
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
	if (ft_arrlen(c) != 3 || ft_arrlen(f) != 3)
		return (0);
	map->f_color[0] = ft_atoi(f[0]);
	map->f_color[1] = ft_atoi(f[1]);
	map->f_color[2] = ft_atoi(f[2]);
	map->c_color[0] = ft_atoi(c[0]);
	map->c_color[1] = ft_atoi(c[1]);
	map->c_color[2] = ft_atoi(c[2]);	
	return (1);
}


int	store(t_book *record)
{
	t_map	*map;

	map = record->map_table;
	map->map_tab = record->map;
	map->map_name = record->file;
	
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