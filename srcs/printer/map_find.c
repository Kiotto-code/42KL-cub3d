/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:32:35 by yichan            #+#    #+#             */
/*   Updated: 2024/01/10 18:24:56 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_find(t_book *record)
{
	const char	*order[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	char		**content;
	int			i;

	content = record->file_content;
	i = 0;
	while (*content)
	{
		if (!(ft_strlead(*content, order[i]) || ft_is_all_space(*content)))
			return (FAIL);
		i++;
		content++;
		if (order[i] == NULL)
			break ;
	}
	record->map = ft_duparr(content);
	return (SUCCESS);
}
