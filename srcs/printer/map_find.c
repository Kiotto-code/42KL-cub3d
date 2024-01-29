/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:32:35 by yichan            #+#    #+#             */
/*   Updated: 2024/01/27 00:08:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	**ft_subarr(char **arr, size_t start, size_t end)
// {
// 	char	**ret;
// 	size_t		arr_len;

// 	if (!arr)
// 		return (NULL);
// 	arr_len = end - start;
// 	ret = ft_calloc(sizeof(char *) * (arr_len + 1));
// 	ret[arr_len] = 0;
// 	while (--arr_len >= 0 && arr_len >= start && arr[arr_len])
// 	{
// 		ret[arr_len] = ft_strdup(arr[end]);
// 		end--;
// 	}
// 	return (ret);
// }

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
	// record->elem_record =  content
	record->map = ft_duparr(content);
	return (SUCCESS);
}
