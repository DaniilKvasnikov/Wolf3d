/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 04:03:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 16:57:56 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_map_check(t_data *data)
{
	if (data->mydata->map.map == NULL)
	{
		ft_putendl_fd("Map error", 2);
		exit(1);
	}
}

void			ft_raycast(t_data *data)
{
	t_raycast r;

	ft_map_check(data);
	r.x = -1;
	while (++r.x < WIN_W)
	{
		ft_raycast_block1(data, &r);
		ft_raycast_block2(data, &r);
		if (r.draw_pos[0] < 0)
			r.draw_pos[0] = 0;
		r.draw_pos[1] = r.line_height / 2 + WIN_H / 2;
		if (r.draw_pos[1] >= WIN_H)
			r.draw_pos[1] = WIN_H - 1;
		data->mydata->map.flags[r.mapy * data->mydata->map.size[0] + r.mapx] =
		1;
		r.tex_num = data->mydata->map.map[
			r.mapy * data->mydata->map.size[0] + r.mapx] - 1;
		if (!ft_is_flag(data, "-c"))
			r.tex_num = 1 * (r.side == 1 && r.stepx >= 0) + 2 * (r.side == 2 &&
		r.stepy >= 0) + 3 * (r.side == 1 && r.stepx < 0) + 4 * (r.side == 2
		&& r.stepy < 0);
		ft_raycast_block3(data, &r);
		ft_raycast_block4(&r);
		ft_raycast_block5(data, &r);
	}
}
