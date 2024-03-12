/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:55:50 by yichan            #+#    #+#             */
/*   Updated: 2024/03/12 17:11:46 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	keypress(int keycode, t_data *data)
// {
// 	open_close(keycode, data);
// 	if (keycode == 13)
// 		data->keystate.w = 1;
// 	if (keycode == 0)
// 		data->keystate.a = 1;
// 	if (keycode == 1)
// 		data->keystate.s = 1;
// 	if (keycode == 2)
// 		data->keystate.d = 1;
// 	else if (keycode == 124)
// 		data->keystate.l = 1;
// 	else if (keycode == 123)
// 		data->keystate.r = 1;
// 	else if (keycode == 49)
// 		data->keystate.q = 1;
// 	else if (keycode == 53)
// 		data->keystate.esc = 1;
// 	else if (keycode == 35)
// 		data->keystate.o = 1;
// 	else if (keycode == 8)
// 		data->keystate.c = 1;
// 	return (0);
// }

void	open_close(int keycode, t_data *data)
{
	int	pov;
	int	cell_x;
	int	cell_y;
	// const char door_state[2] = {'C', 'O'};

	if (keycode != 14)
		return ;
	cell_x = data->position->x_cell;
	cell_y = data->position->y_cell;
	pov = data->position->pov;
	if (pov <= 45 || pov >= 315)
		cell_y--;
	else if (pov > 45 && pov < 135)
		cell_x++;
	else if (pov > 135 && pov < 225)
		cell_y++;
	else if (pov > 225 && pov < 315)
		cell_x--;
	if (data->map->map_tab[cell_y][cell_x] == 'C')
		data->map->map_tab[cell_y][cell_x] = 'O';
	else if (data->map->map_tab[cell_y][cell_x] == 'O')
		data->map->map_tab[cell_y][cell_x] = 'C';
	// if 
}

int	keypress(int keycode, t_data *data)
{
	open_close(keycode, data);
	if (keycode == 13)
		data->keystate.w = 1;
	else if (keycode == 0)
		data->keystate.a = 1;
	else if (keycode == 1)
		data->keystate.s = 1;
	else if (keycode == 2)
		data->keystate.d = 1;
	else if (keycode == 124)
		data->keystate.left = 1;
	else if (keycode == 123)
		data->keystate.right = 1;
	else if (keycode == 49)
		data->keystate.space = 1;
	else if (keycode == 53)
		data->keystate.esc = 1;
	// else if (keycode == 35)
	// 	data->keystate.o = 1;
	// else if (keycode == 8)
	// 	data->keystate.c = 1;
	return (0);
}

// int	keyrelease(int keycode, t_data *data)
// {
// 	if (keycode == 13)
// 		data->keystate.w = 0;
// 	if (keycode == 0)
// 		data->keystate.a = 0;
// 	if (keycode == 1)
// 		data->keystate.s = 0;
// 	if (keycode == 2)
// 		data->keystate.d = 0;
// 	else if (keycode == 124)
// 		data->keystate.l = 0;
// 	else if (keycode == 123)
// 		data->keystate.r = 0;
// 	else if (keycode == 49)
// 		data->keystate.q = 0;
// 	else if (keycode == 35)
// 		data->keystate.o = 0;
// 	else if (keycode == 8)
// 		data->keystate.c = 0;
// 	return (0);
// }
int	keyrelease(int keycode, t_data *data)
{
	if (keycode == 13)
		data->keystate.w = 0;
	else if (keycode == 0)
		data->keystate.a = 0;
	else if (keycode == 1)
		data->keystate.s = 0;
	else if (keycode == 2)
		data->keystate.d = 0;
	else if (keycode == 124)
		data->keystate.left = 0;
	else if (keycode == 123)
		data->keystate.right = 0;
	else if (keycode == 49)
		data->keystate.space = 0;
	// else if (keycode == 35)
	// 	data->keystate.click = 0;
	// else if (keycode == 8)
	// 	data->keystate.c = 0;
	return (0);
}
