/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:54:22 by yichan            #+#    #+#             */
/*   Updated: 2024/01/27 23:54:28 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_arr(char **arr, char *prompt)
{
	size_t	i;

	i = 0;
	printf(BLUE"CHECKING: %s\n"RESET, prompt);
	while (arr[i])
	{
		// printf("%s\t: ", prompt);
		// fflush(stdout);
		ft_putendl_fd(arr[i], 1);
		i++;
	}
}