/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:55:50 by yichan            #+#    #+#             */
/*   Updated: 2024/03/10 23:56:04 by yichan           ###   ########.fr       */
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
		data->keystate.l = 1;
	else if (keycode == 123)
		data->keystate.r = 1;
	else if (keycode == 49)
		data->keystate.q = 1;
	else if (keycode == 53)
		data->keystate.esc = 1;
	else if (keycode == 35)
		data->keystate.o = 1;
	else if (keycode == 8)
		data->keystate.c = 1;
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
		data->keystate.l = 0;
	else if (keycode == 123)
		data->keystate.r = 0;
	else if (keycode == 49)
		data->keystate.q = 0;
	else if (keycode == 35)
		data->keystate.o = 0;
	else if (keycode == 8)
		data->keystate.c = 0;
	return (0);
}
