/* ************************************************************************** */
/*																																						*/
/*																												:::			::::::::	 */
/*	 ft_draw.c																					:+:			:+:		:+:	 */
/*																										+:+ +:+				 +:+		 */
/*	 By: rrhaenys <rrhaenys@student.42.fr>					+#+	+:+			 +#+				*/
/*																								+#+#+#+#+#+	 +#+					 */
/*	 Created: 2019/02/05 06:19:33 by rrhaenys					#+#		#+#						 */
/*	 Updated: 2019/02/18 19:15:51 by rrhaenys				 ###	 ########.fr			 */
/*																																						*/
/* ************************************************************************** */

#include "main.h"

void	line_fast(t_data *env, double *p1, double *p2, int color)
{
	int i;
	int x[2];
	int p[2];

	x[0] = abs((int)(p2[Y_P] - p1[Y_P])) >> 1;
	x[1] = abs((int)(p2[X_P] - p1[X_P])) >> 1;
	ft_draw_px(env, (p[0] = p1[X_P]),
				(p[1] = p1[Y_P]), color);
	if (((i = -1) == -1) && abs((int)(p2[X_P] - p1[X_P])) >=
		abs((int)(p2[Y_P] - p1[Y_P])))
		while (++i < abs((int)(p2[X_P] - p1[X_P])))
		{
			BLOCK_2(x[1], abs((int)(p2[X_P] - p1[X_P])), p[1],
			SGN(p2[Y_P] - p1[Y_P]), abs((int)(p2[Y_P] - p1[Y_P])));
			ft_draw_px(env, (p[0] += SGN(p2[X_P] - p1[X_P])), p[1], color);
		}
	else
		while (++i < abs((int)(p2[Y_P] - p1[Y_P])))
		{
			BLOCK_2(x[0], abs((int)(p2[Y_P] - p1[Y_P])), p[0],
			SGN(p2[X_P] - p1[X_P]), abs((int)(p2[X_P] - p1[X_P])));
			ft_draw_px(env, p[0], (p[1] += SGN(p2[Y_P] - p1[Y_P])), color);
		}
}

#include <stdio.h>

void			ft_draw_px(t_data *data, int x, int y, int color)
{
	float z;

	if (data->img->size_l <= 100)
		return ;
	x = (int)(x);
	y = (int)(WIN_H - y - 1);
	z = x + (y * WIN_W);
	if (z >= 0 && z < WIN_S &&
		x >= 0 && x <= WIN_W &&
		y >= 0)
		data->img->data[y * WIN_W + x] = color;
}

void			line_vertical(t_data *data, int x, int *y, int color)
{
	int	ind_y;

	ind_y = y[0] - 1;
	while (++ind_y <= y[1])
		data->img->data[ind_y * WIN_H + x] = color;
}

void			testfun(t_data *data)
{
	int		x;
	int		draw_pos[2];

	x = -1;
	while (++x < WIN_W)
	{
		double ray_dirx = data->mydata->dirX +
		(data->mydata->planeX * ((2 * x) / (double)WIN_W - 1));
		double ray_diry = data->mydata->dirY +
		(data->mydata->planeY * ((2 * x) / (double)WIN_W - 1));
		//which box of the map we're in
		int mapX = (int)data->mydata->posX;
		int mapY = (int)data->mydata->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / ray_dirx);
		double deltaDistY = fabs(1 / ray_diry);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		stepX = (ray_dirx >= 0) * 2 - 1;
		if (ray_dirx < 0)
			sideDistX = (data->mydata->posX - (double)mapX) * deltaDistX;
		else
			sideDistX = ((double)mapX + 1.0 - data->mydata->posX) * deltaDistX;
		stepY = (ray_diry >= 0) * 2 - 1;
		if (ray_diry < 0)
			sideDistY = (data->mydata->posY - (double)mapY) * deltaDistY;
		else
			sideDistY = ((double)mapY + 1.0 - data->mydata->posY) * deltaDistY;
		while (data->mydata->map.map[mapY * data->mydata->map.size[0] + mapX] == 0)
		{
			side = (sideDistX >= sideDistY) + 1;
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
			}
		}
		if (side == 1)
			perpWallDist = (mapX - data->mydata->posX + (1 - stepX) / 2) / ray_dirx;
		else
			perpWallDist = (mapY - data->mydata->posY + (1 - stepY) / 2) / ray_diry;
		int lineHeight = (int)(WIN_H / perpWallDist);
		draw_pos[0] = -lineHeight / 2 + WIN_H / 2;
		if (draw_pos[0] < 0)
			draw_pos[0] = 0;
		draw_pos[1] = lineHeight / 2 + WIN_H / 2;
		if (draw_pos[1] >= WIN_H)
			draw_pos[1] = WIN_H - 1;
		int color;
/*		switch (data->mydata->map.map[mapY * data->mydata->map.size[0] + mapX])
		{
		case 1:
			color = RGB_Red;
			break;
		case 2:
			color = RGB_Green;
			break;
		case 3:
			color = RGB_Blue;
			break;
		case 4:
			color = 0x00ffff;
			break;
		default:
			color = RGB_Yellow;
			break;
		}*/
//		side += (stepX < 0) + (stepY < 0);
		color = RGB_Red * (side == 1 && stepX >= 0) + RGB_Green * (side == 2 && stepY >= 0) + RGB_Blue * (side == 1 && stepX < 0) + RGB_Yellow * (side == 2 && stepY < 0);
		line_vertical(data, x, draw_pos, color);
	}
}

int				ft_draw(t_data *data)
{
	ft_clearwin(data);
	testfun(data);
	int		x;
	int		y;
	for(x = 0; x < 64; x++)
		for(y = 0; y < 64; y++)
			data->img->data[y * WIN_W + x] = data->mydata->texture[0].data[x * 64 + y];
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	return (1);
}
