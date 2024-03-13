/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:51:53 by yichan            #+#    #+#             */
/*   Updated: 2024/03/13 18:50:16 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_subarr(char **arr, int start, int end)
{
	char	**ret;
	size_t		arr_len;
	int		range_len;

	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
	range_len = end - start +1;
	ret = ft_calloc(sizeof(char *) * (range_len +1));
	if (!ret)
		return (printf("ft_subarr: malloc failed\n"), NULL);
	else
		ft_putstr_fd("ft_subarr: malloc success\n", 2);
	// printf("range_len: %zu\n", range_len);
	ret[range_len] = 0;
	// printf(GREEN"ret[0]: %s\n"RESET,ret[0]);
	// printf(GREEN"arr[0]: %s\n"RESET,arr[0]);
	while (--range_len >= 0 && end >= start)
	{
		// printf(GREEN"range_len: %d\n"RESET,range_len);
		// printf(GREEN"end: %d\n"RESET,end);
		// printf(GREEN"arr[end]: %s\n"RESET,arr[end]);
		// printf(GREEN"ret[range_len]: %s\n"RESET,ret[range_len]);
		// printf(GREEN"arr[end]: %s\n"RESET,arr[end]);
		ret[range_len] = ft_strdup(arr[end]);
		end--;
		// printf("ret[%zu]: %s\n", range_len, ret[range_len]);
	}
	return (ret);
}
