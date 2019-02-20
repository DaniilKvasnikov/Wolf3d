/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 15:22:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		line_fast(t_data *env, double *p1, double *p2, int color)
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

void		ft_draw_px(t_data *data, int x, int y, int color)
{
	float z;

	data->img->data[y * WIN_W + x] = color;
	return ;
	if (data->img->size_l <= 100)
		return ;
	x = (int)(x);
	y = (int)(WIN_H - y - 1);
	z = x + (y * WIN_W);
	if (z >= 0 && z < WIN_S &&
		x >= 0 && x <= WIN_W &&
		y >= 0)
		data->img->data[WIN_W - (y * WIN_W + 1) + x] = color;
}

void		line_vertical(t_data *data, int x, int *y, int color)
{
	int	ind_y;

	ind_y = y[0] - 1;
	while (++ind_y <= y[1])
		data->img->data[WIN_H - (ind_y * WIN_H + 1) + x] = color;
}

void		ft_regenerator(t_data *data)
{
	double	player_p[2];
	double	dir[2];
	int		cube[2];

	player_p[0] = data->mydata->posx;
	player_p[1] = data->mydata->posy;
	dir[0] = data->mydata->dirx;
	dir[1] = data->mydata->diry;
	cube[0] = data->mydata->posx - data->mydata->dirx;
	cube[1] = data->mydata->posy - data->mydata->diry;
	if (cube[0] > 0 && cube[1] > 0 &&
		cube[0] < data->mydata->map.size[0] &&
		cube[1] < data->mydata->map.size[1])
	{
		ft_printf("%d %d\n", cube[1], cube[0]);
		data->mydata->map.map[data->mydata->map.size[0] * cube[1] + cube[0]] = rand() % 2;
	}
//	printf("x=%f y=%f dx=%f dy=%f\n", player_p[0], player_p[1], dir[0], dir[1]);
}

void		ft_linefast_int(t_data *data, int *p1, int *p2, int color)
{
	double	f1[2];
	double	f2[2];

	f1[0] = p1[0];
	f1[1] = p1[1];
	f2[0] = p2[0];
	f2[1] = p2[1];
	line_fast(data, f1, f2, color);
}

void		ft_map(t_data *data)
{
	int		pos[2];
	int		point[2];

	pos[0] = data->mydata->map.size[0];
	while (--pos[0] >= 0)
	{
		pos[1] = -1;
		while (++pos[1] < data->mydata->map.size[1])
		{
			if (data->mydata->map.map[
				pos[0] + pos[1] * data->mydata->map.size[0]] != 0)
				{
					point[0] = (data->mydata->map.size[0] - 1 - pos[0]) * 5 + 50;
					point[1] = pos[1] * 5 + 50;
					ft_draw_square(data, point, 2, 0xffffff);
				}
		}
	}
	point[0] = (data->mydata->map.size[0] - data->mydata->posx - 0.5) * 5 + 50;
	point[1] = (data->mydata->posy - 0.5) * 5 + 50;
	ft_draw_square(data, point, 2, 0x00ff00);
	pos[0] = point[0] - data->mydata->dirx * 5;
	pos[1] = point[1] + data->mydata->diry * 5;
	ft_linefast_int(data, point, pos, 0xff0000);
}

int			ft_draw(t_data *data)
{
//	ft_regenerator(data);
	if (data->mydata->move != 0)
		player_move(data, 0.03 * data->mydata->move * data->mydata->run);
	if (data->mydata->turn != 0)
		player_turn(data, 0.02 * data->mydata->turn);
	ft_clearwin(data);
	ft_raycast(data);
	ft_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	return (1);
}
