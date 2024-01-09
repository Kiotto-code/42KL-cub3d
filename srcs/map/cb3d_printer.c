/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb3d_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:08 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 14:55:56 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_print(char **db_arr)
{
    if (db_arr == NULL)
        return false;
    // printf("check : Is map_print here??\n");
    for (int i = 0; db_arr[i]; i++)
		printf(BLUE"check: !!!!!%s\n"RESET, db_arr[i]);
    return true;
} 