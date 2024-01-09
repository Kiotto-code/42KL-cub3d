/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:49:19 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 18:50:15 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_wall(char *str)
{
	int	status;

	status = 1;
	while (*str++ && status)
	{
		if (*str != '1')
			status &= 0;
	}
	return (status);
}

int	ends_wall(char **map)
{
	int		status;
	char	*mapline;

	status = 1;
	mapline = *map;
	while (mapline && *mapline)
	{
		if (mapline[ft_strlen(mapline)] != '1')
			status &= 0;
		if (mapline[0] != '1')
			status &= 0;
		mapline = *(map++);
	}
	return (status);
}

int	map_valid_wall_surround(t_book *record)
{
	if (record->map[0] && all_wall(record->map[0]) == 0)
		return (1);
	if (ends_wall(record->map) == 0)
		return (1);
	return (0);
}

int	map_file_checking(t_book *record)
{
	int		fd;
	char	*tmp;
	char	*fileline;

	fd = open(record->file, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("failed open file", 2), 1);
	fileline = ft_strdup("");
	while (true)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		fileline = ft_strjoinf(fileline, tmp);
		free(tmp);
	}
	record->file_content = ft_split(fileline, '\n');
	if (map_find(record) == 1)
	{
		ft_putendl_fd("invalid file sequence format as subject required", 2);
		return (1);
	}
	if (map_valid_wall_surround(record) == 1)
		return (ft_putendl_fd("invalid map as not wall surrounded", 2), 1);
	return (0);
}
