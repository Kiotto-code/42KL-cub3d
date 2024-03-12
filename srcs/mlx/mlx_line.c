/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mlx_line.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yichan <yichan@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/24 17:11:59 by yichan			#+#	#+#			 */
/*   Updated: 2024/01/25 16:44:18 by yichan		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_line_inc(float x_inc, float y_inc, t_book *record)
{
	float curr_x = record->line_initial.x;
	float curr_y = record->line_initial.y;
	int i;

	i = 0;
	while (i++ <= record->line_steps)
	{
		mlx_pixel_put(&record->data->mlx, record->win, curr_x, curr_y, 0xFFFFFF);
		curr_x += x_inc;
		curr_y += y_inc;
	}

}

void	mlx_draw_line(int x0, int y0, int x1, int y1, t_book *record)
{
	int dif_x;
	int dif_y;
	float steps;

	dif_x = x1 - x0;
	dif_y = y1 - y0;
	record->line_initial = (t_coor){x0, y0};
	steps = abs(dif_x) > abs(dif_y) ? abs (dif_x) : abs (dif_y);
	record->line_steps = steps;

	mlx_line_inc(dif_x / steps, dif_y / steps, record);

	// float xIncrement = dif_x / (float)steps;
	// float xIncrement = dif_y / (float)steps;

}