/* ************************************************************************** */
/*																																						*/
/*																												:::			::::::::	 */
/*	 ft_key_release.c																	 :+:			:+:		:+:	 */
/*																										+:+ +:+				 +:+		 */
/*	 By: rrhaenys <rrhaenys@student.42.fr>					+#+	+:+			 +#+				*/
/*																								+#+#+#+#+#+	 +#+					 */
/*	 Created: 2019/02/06 01:36:25 by rrhaenys					#+#		#+#						 */
/*	 Updated: 2019/02/18 19:59:40 by rrhaenys				 ###	 ########.fr			 */
/*																																						*/
/* ************************************************************************** */

#include "main.h"

int				key_release(int key, t_data *data)
{
	double	rot_speed;
	double	move_speed;
	double	old_dirx;
	double	old_planex;

	rot_speed = 0.03;
	move_speed = 0.09;
	if (key == 53)
		ft_close(data);
	else if (key == 13 || key == 126)
	{
		if(data->mydata->map.map[((int)(data->mydata->posX + data->mydata->dirX * move_speed)) + ((int)(data->mydata->posY)) * data->mydata->map.size[0]] == 0)
			data->mydata->posX += data->mydata->dirX * move_speed;
		if(data->mydata->map.map[((int)(data->mydata->posX)) + ((int)(data->mydata->posY + data->mydata->dirY * move_speed)) * data->mydata->map.size[0]] == 0)
			data->mydata->posY += data->mydata->dirY * move_speed;
	}
	else if (key == 1 || key == 125)
	{
		if(data->mydata->map.map[((int)(data->mydata->posX - data->mydata->dirX * move_speed)) + ((int)(data->mydata->posY)) * data->mydata->map.size[0]] == 0)
			data->mydata->posX -= data->mydata->dirX * move_speed;
		if(data->mydata->map.map[((int)(data->mydata->posX)) + ((int)(data->mydata->posY - data->mydata->dirY * move_speed)) * data->mydata->map.size[0]] == 0)
			data->mydata->posY -= data->mydata->dirY * move_speed;
	}
	else if (key == 2 || key == 124)
	{
		old_dirx = data->mydata->dirX;
		data->mydata->dirX = data->mydata->dirX * cos(-rot_speed) - data->mydata->dirY * sin(-rot_speed);
		data->mydata->dirY = old_dirx * sin(-rot_speed) + data->mydata->dirY * cos(-rot_speed);
		old_planex = data->mydata->planeX;
		data->mydata->planeX = data->mydata->planeX * cos(-rot_speed) - data->mydata->planeY * sin(-rot_speed);
		data->mydata->planeY = old_planex * sin(-rot_speed) + data->mydata->planeY * cos(-rot_speed);
	}
	else if (key == 0 || key == 123)
	{
		old_dirx = data->mydata->dirX;
		data->mydata->dirX = data->mydata->dirX * cos(rot_speed) - data->mydata->dirY * sin(rot_speed);
		data->mydata->dirY = old_dirx * sin(rot_speed) + data->mydata->dirY * cos(rot_speed);
		old_planex = data->mydata->planeX;
		data->mydata->planeX = data->mydata->planeX * cos(rot_speed) - data->mydata->planeY * sin(rot_speed);
		data->mydata->planeY = old_planex * sin(rot_speed) + data->mydata->planeY * cos(rot_speed);
	}
	else
		ft_printf("key=%d\n", key);
	return (1);
}
