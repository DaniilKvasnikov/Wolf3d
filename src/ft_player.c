/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:22:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/06 03:10:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <math.h>

void	ft_create_payer(t_data *data)
{
	data->mydata->player.pos[0] = 0;
	data->mydata->player.pos[1] = 0;
	data->mydata->player.pos[2] = 0;
	data->mydata->player.angle[0] = 0;
	data->mydata->player.angle[1] = 0;
}

void	ft_turn_player(t_data *data, int turn)
{
	data->mydata->player.angle[0] += M_PI_4 * turn;
	if (data->mydata->player.angle[0] >= M_PI * 2)
		data->mydata->player.angle[0] -= M_PI * 2;
	if (data->mydata->player.angle[0] < 0)
		data->mydata->player.angle[0] += M_PI * 2;
}

void	ft_player_step_forward(t_data *data, int turn)
{
	double	len;

	len = 5.0;
	data->mydata->player.pos[0] += sin(data->mydata->player.angle[0]) * len * turn;
	data->mydata->player.pos[1] += cos(data->mydata->player.angle[0]) * len * turn;
}

void	ft_draw_player(t_data *data)
{
	double	pos[3];
	double	to[3];
	double	len;

	len = 5.0;
	pos[0] = WIN_W / 2 + data->mydata->player.pos[0];
	pos[1] = WIN_H / 2 + data->mydata->player.pos[1];
	to[0] = pos[0] + sin(data->mydata->player.angle[0]) * len;
	to[1] = pos[1] + cos(data->mydata->player.angle[0]) * len;
	line_fast(data, pos, to, 0x00ff00);
	ft_draw_px(data, WIN_W / 2 + data->mydata->player.pos[0],
				WIN_H / 2 + data->mydata->player.pos[1], 0xff0000);
}