/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:04:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 17:05:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_draw_map(t_data *data)
{
	int		pos[2];
	int		point[2];

	pos[0] = data->mydata->map.size[0];
	while (--pos[0] >= 0)
	{
		pos[1] = -1;
		while (++pos[1] < data->mydata->map.size[1])
			if (data->mydata->map.map[
					pos[0] + pos[1] * data->mydata->map.size[0]] != 0 &&
				(data->mydata->map.flags[
					pos[0] + pos[1] * data->mydata->map.size[0]] == 1 ||
					!ft_is_flag(data, "-f")))
			{
				point[0] = (data->mydata->map.size[0] - 1 - pos[0]) * 5 + 50;
				point[1] = pos[1] * 5 + 50;
				ft_draw_square(data, point, 2, 0xffffff);
			}
	}
	point[0] = (data->mydata->map.size[0] - data->mydata->posx - 0.5) * 5 + 50;
	point[1] = (data->mydata->posy - 0.5) * 5 + 50;
	ft_draw_square(data, point, 2, 0x00ff00);
	pos[0] = point[0] - data->mydata->dirx * 5;
	pos[1] = point[1] + data->mydata->diry * 5;
	ft_linefast_int(data, point, pos, 0xff0000);
}

void		ft_map_clear(t_data *data)
{
	int	index;
	int	size;

	ft_map_check(data);
	index = -1;
	size = data->mydata->map.size[0] * data->mydata->map.size[1];
	while (++index < size)
		data->mydata->map.flags[index] = 0;
}
