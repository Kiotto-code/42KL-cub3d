/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:04:29 by yichan            #+#    #+#             */
/*   Updated: 2023/08/16 04:02:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	main(int ac, char **av)
{
	t_book	record;

	if (ac != 2)
		ft_error("WRONG ARGUMENT", 2);
	record = (t_book){0};
	record.file = ft_strdup(av[1]);
	map_file_checking(&record);
}