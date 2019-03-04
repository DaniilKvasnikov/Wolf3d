/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/03/04 13:16:44 by rrhaenys         ###   ########.fr       */
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
	data->img->data[y * WIN_W + x] = color;
}

void		line_vertical(t_data *data, int x, int *y, int color)
{
	int	ind_y;

	ind_y = y[0] - 1;
	while (++ind_y <= y[1])
		data->img->data[ind_y * WIN_H + x] = color;
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

int			ft_draw(t_data *data)
{
	if (data->mydata->move != 0)
		player_move(data, 0.03 * data->mydata->move * data->mydata->run);
	if (data->mydata->turn != 0)
		player_turn(data, 0.02 * data->mydata->turn * sqrt(data->mydata->run));
	ft_clearwin(data);
	ft_map_clear(data);
	ft_raycast(data);
	if (ft_is_flag(data, "-m") || ft_is_flag(data, "-f"))
		ft_draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	return (1);
}
