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

int worldmap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int				key_release(int key, t_data *data)
{
	double	rotSpeed;
	double	moveSpeed;

	rotSpeed = 0.03;
	moveSpeed = 0.09;
	if (key == 53)
		ft_close(data);
	//move forward if no wall in front of you
	else if (key == 13)
	{
		if(worldmap[(int)(data->mydata->posX + data->mydata->dirX * moveSpeed)][(int)(data->mydata->posY)] == 0)
			data->mydata->posX += data->mydata->dirX * moveSpeed;
		if(worldmap[(int)(data->mydata->posX)][(int)(data->mydata->posY + data->mydata->dirY * moveSpeed)] == 0)
			data->mydata->posY += data->mydata->dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	else if (key == 1)
	{
		if(worldmap[(int)(data->mydata->posX - data->mydata->dirX * moveSpeed)][(int)(data->mydata->posY)] == 0)
			data->mydata->posX -= data->mydata->dirX * moveSpeed;
		if(worldmap[(int)(data->mydata->posX)][(int)(data->mydata->posY - data->mydata->dirY * moveSpeed)] == 0)
			data->mydata->posY -= data->mydata->dirY * moveSpeed;
	}
	//rotate to the right
	else if (key == 2)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->mydata->dirX;
		data->mydata->dirX = data->mydata->dirX * cos(-rotSpeed) - data->mydata->dirY * sin(-rotSpeed);
		data->mydata->dirY = oldDirX * sin(-rotSpeed) + data->mydata->dirY * cos(-rotSpeed);
		double oldPlaneX = data->mydata->planeX;
		data->mydata->planeX = data->mydata->planeX * cos(-rotSpeed) - data->mydata->planeY * sin(-rotSpeed);
		data->mydata->planeY = oldPlaneX * sin(-rotSpeed) + data->mydata->planeY * cos(-rotSpeed);
	}
	//rotate to the left
	else if (key == 0)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->mydata->dirX;
		data->mydata->dirX = data->mydata->dirX * cos(rotSpeed) - data->mydata->dirY * sin(rotSpeed);
		data->mydata->dirY = oldDirX * sin(rotSpeed) + data->mydata->dirY * cos(rotSpeed);
		double oldPlaneX = data->mydata->planeX;
		data->mydata->planeX = data->mydata->planeX * cos(rotSpeed) - data->mydata->planeY * sin(rotSpeed);
		data->mydata->planeY = oldPlaneX * sin(rotSpeed) + data->mydata->planeY * cos(rotSpeed);
	}
	ft_printf("key=%d\n", key);
	return (1);
}
