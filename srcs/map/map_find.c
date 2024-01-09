/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:32:35 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 17:12:23 by yichan           ###   ########.fr       */
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
			return (1);
		i++;
		content++;
		if (order[i] == NULL)
			break ;
	}
	printf(BG_BRIGHT_RED"check: %s\n", *content);
	record->map = ft_duparr(content);
	printf(BG_GREEN"check: end %s\n", *content);
	return (0);
}
