/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:50:04 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 14:56:29 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdbool.h>
# include "color.h"
# include "../libft/includes/libft.h"

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define EXIT_EVENT	17
# define EXIT_MASK	0

/* Colors */
// # define WHITE		-1

typedef struct s_book
{
	const char		*file;
	char			**file_content;
	char			**map;
}	t_book;

//map_calidity.c
int	map_valid_wall_surround(t_book *record);
int	map_file_checking(t_book *record);

//map_find.c
int	map_find(t_book *record);

//cb3d_printer.c
int map_print(char **db_arr);

#endif