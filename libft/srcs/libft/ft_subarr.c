/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:51:53 by yichan            #+#    #+#             */
/*   Updated: 2024/01/27 23:52:30 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_subarr(char **arr, size_t start, size_t end)
{
	char	**ret;
	size_t		arr_len;
	size_t		range_len;

	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
	range_len = end - start;
	ret = ft_calloc(sizeof(char *) * (range_len +1));
	if (!ret)
		return (printf("ft_subarr: malloc failed\n"), NULL);
	else
		ft_putstr_fd("ft_subarr: malloc success\n", 2);
	printf("range_len: %zu\n", range_len);
	ret[range_len] = 0;
	while (--range_len >= 0 && end > start)
	{
		ret[range_len] = ft_strdup(arr[end]);
		end--;
	}
	return (ret);
}
