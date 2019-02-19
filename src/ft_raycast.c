/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 04:03:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/19 06:38:41 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_test1(t_data *data, t_raycast *r)
{
	r->ray_dirx = data->mydata->dirx +
	(data->mydata->planex * ((2 * r->x) / (double)WIN_W - 1));
	r->ray_diry = data->mydata->diry +
	(data->mydata->planey * ((2 * r->x) / (double)WIN_W - 1));
	r->mapx = (int)data->mydata->posx;
	r->mapy = (int)data->mydata->posy;
	r->delta_distx = fabs(1 / r->ray_dirx);
	r->delta_disty = fabs(1 / r->ray_diry);
	r->stepx = (r->ray_dirx >= 0) * 2 - 1;
	if (r->ray_dirx < 0)
		r->side_distx = (data->mydata->posx - (double)r->mapx) * r->delta_distx;
	else
		r->side_distx = ((double)r->mapx + 1.0 - data->mydata->posx) *
		r->delta_distx;
	r->stepy = (r->ray_diry >= 0) * 2 - 1;
	if (r->ray_diry < 0)
		r->side_disty = (data->mydata->posy - (double)r->mapy) * r->delta_disty;
	else
		r->side_disty = ((double)r->mapy + 1.0 - data->mydata->posy) *
		r->delta_disty;
}

void			ft_test2(t_data *data, t_raycast *r)
{
	while (data->mydata->map.map[
		r->mapy * data->mydata->map.size[0] + r->mapx] == 0)
	{
		r->side = (r->side_distx >= r->side_disty) + 1;
		if (r->side_distx < r->side_disty)
		{
			r->side_distx += r->delta_distx;
			r->mapx += r->stepx;
		}
		else
		{
			r->side_disty += r->delta_disty;
			r->mapy += r->stepy;
		}
	}
	if (r->side == 1)
		r->perp_walldist =
		(r->mapx - data->mydata->posx + (1 - r->stepx) / 2) / r->ray_dirx;
	else
		r->perp_walldist =
		(r->mapy - data->mydata->posy + (1 - r->stepy) / 2) / r->ray_diry;
	r->line_height = (int)(WIN_H / r->perp_walldist);
	r->draw_pos[0] = -r->line_height / 2 + WIN_H / 2;
}

void			ft_test3(t_data *data, t_raycast *r)
{
	r->tex_num = data->mydata->map.map[
		r->mapy * data->mydata->map.size[0] + r->mapx] - 1;
	r->tex_num = 1 * (r->side == 1 && r->stepx >= 0) + 2 * (r->side == 2 &&
	r->stepy >= 0) + 3 * (r->side == 1 && r->stepx < 0) + 4 * (r->side == 2 &&
	r->stepy < 0);
	if (r->tex_num <= 4)
	{
		if (r->side == 1)
			r->wallx = data->mydata->posy + r->perp_walldist * r->ray_diry;
		else
			r->wallx = data->mydata->posx + r->perp_walldist * r->ray_dirx;
		r->wallx -= floor((r->wallx));
		r->texx = (int)(r->wallx * (double)(64));
		r->y = r->draw_pos[0] - 1;
		while (++r->y < r->draw_pos[1])
		{
			r->d = r->y * 256 - WIN_H * 128 + r->line_height * 128;
			r->texy = ((r->d * 64) / r->line_height) / 256;
			r->color = data->mydata->texture[r->tex_num].data[64 * r->texy +
			r->texx];
			if (r->side == 2)
				r->color = (r->color >> 1) & 8355711;
			data->img->data[(r->y) * WIN_W + r->x] = r->color;
		}
	}
}

void			ft_test4(t_data *data, t_raycast *r)
{
	if (r->side == 1 && r->ray_dirx > 0)
	{
		r->floorx_wall = r->mapx;
		r->floory_wall = (double)r->mapy + r->wallx;
	}
	else if (r->side == 1 && r->ray_dirx < 0)
	{
		r->floorx_wall = (double)r->mapx + 1.0;
		r->floory_wall = (double)r->mapy + r->wallx;
	}
	else if (r->side == 2 && r->ray_diry > 0)
	{
		r->floorx_wall = (double)r->mapx + r->wallx;
		r->floory_wall = r->mapy;
	}
	else
	{
		r->floorx_wall = (double)r->mapx + r->wallx;
		r->floory_wall = (double)r->mapy + 1.0;
	}
}

void			ft_test5(t_data *data, t_raycast *r)
{
	r->dist_wall = r->perp_walldist;
	r->dist_player = 0.0;
	if (r->draw_pos[1] < 0)
		r->draw_pos[1] = WIN_H;
	r->y = r->draw_pos[1];
	while (++r->y < WIN_H)
	{
		r->current_dist = (double)WIN_H / (2.0 * (double)r->y - (double)WIN_H);
		r->weight = (r->current_dist - r->dist_player) /
		(r->dist_wall - r->dist_player);
		r->current_floorx =
		r->weight * r->floorx_wall + (1.0 - r->weight) * data->mydata->posx;
		r->current_floory =
		r->weight * r->floory_wall + (1.0 - r->weight) * data->mydata->posy;
		r->floor_texx = (int)(r->current_floorx * (double)64) % 64;
		r->floor_texy = (int)(r->current_floory * (double)64) % 64;
		data->img->data[(WIN_H - r->y) * WIN_W + r->x] = (data->mydata->
		texture[1].data[64 * r->floor_texy + r->floor_texx] >> 1) & 8355711;
		data->img->data[(r->y) * WIN_W + r->x] =
		data->mydata->texture[0].data[64 * r->floor_texy + r->floor_texx];
	}
}

void			ft_raycast(t_data *data)
{
	t_raycast r;

	r.x = -1;
	if (data->mydata->map.map == NULL)
	{
		ft_putendl_fd("Map error", 2);
		exit(1);
	}
	while (++r.x < WIN_W)
	{
		ft_test1(data, &r);
		ft_test2(data, &r);
		if (r.draw_pos[0] < 0)
			r.draw_pos[0] = 0;
		r.draw_pos[1] = r.line_height / 2 + WIN_H / 2;
		if (r.draw_pos[1] >= WIN_H)
			r.draw_pos[1] = WIN_H - 1;
		ft_test3(data, &r);
		ft_test4(data, &r);
		ft_test5(data, &r);
	}
}
