/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:25:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 17:00:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			player_move(t_data *data, double move_speed)
{
	data->mydata->posx += data->mydata->dirx * move_speed *
	(data->mydata->map.map[
		((int)(data->mydata->posx + data->mydata->dirx * move_speed)) +
		((int)(data->mydata->posy)) * data->mydata->map.size[0]] == 0);
	data->mydata->posy += data->mydata->diry * move_speed *
	(data->mydata->map.map[((int)(data->mydata->posx)) +
		((int)(data->mydata->posy + data->mydata->diry * move_speed)) *
		data->mydata->map.size[0]] == 0);
}

void			player_turn(t_data *data, double rot_speed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->mydata->dirx;
	data->mydata->dirx = data->mydata->dirx * cos(rot_speed) -
	data->mydata->diry * sin(rot_speed);
	data->mydata->diry = old_dirx * sin(rot_speed) +
	data->mydata->diry * cos(rot_speed);
	old_planex = data->mydata->planex;
	data->mydata->planex = data->mydata->planex * cos(rot_speed) -
	data->mydata->planey * sin(rot_speed);
	data->mydata->planey = old_planex * sin(rot_speed) +
	data->mydata->planey * cos(rot_speed);
}

int				key_release(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	else if (key == 13 || key == 126)
		data->mydata->move -= (data->mydata->move > 0);
	else if (key == 1 || key == 125)
		data->mydata->move += (data->mydata->move < 0);
	else if (key == 2 || key == 124)
		data->mydata->turn += (data->mydata->turn < 0);
	else if (key == 0 || key == 123)
		data->mydata->turn -= (data->mydata->turn > 0);
	else if (key == 257)
		data->mydata->run -= (data->mydata->run == 3) * 2;
	return (1);
}

int				key_press(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	else if (key == 13 || key == 126)
		data->mydata->move += (data->mydata->move <= 0);
	else if (key == 1 || key == 125)
		data->mydata->move -= (data->mydata->move >= 0);
	else if (key == 2 || key == 124)
		data->mydata->turn -= (data->mydata->turn >= 0);
	else if (key == 0 || key == 123)
		data->mydata->turn += (data->mydata->turn <= 0);
	else if (key == 257)
		data->mydata->run += (data->mydata->run == 1) * 2;
	if (ft_is_flag(data, "-k"))
		ft_printf("key_press=%d\n", key);
	return (1);
}
