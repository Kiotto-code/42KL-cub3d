/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb3d_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:08 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 18:47:33 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_print(char **db_arr)
{
	int	i;

	i = -1;
	if (db_arr == NULL)
		return (false);
	while (db_arr[++i])
		printf(BLUE"check: !!!!!%s\n"RESET, db_arr[i]);
	return (true);
}
