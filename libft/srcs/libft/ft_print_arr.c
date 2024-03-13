/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:54:22 by yichan            #+#    #+#             */
/*   Updated: 2024/03/13 19:40:55 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_arr(char **arr, char *prompt)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		if (prompt)
			ft_putstr_fd(prompt, 1);
		ft_putstr_fd(BLUE"CHECKING: %s: "RESET, 1);
		ft_putendl_fd(arr[i], 1);
		fflush(stdout);
		i++;
	}
}