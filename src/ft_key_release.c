/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:36:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/06 03:11:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				key_release(int key, t_data *data)
{
	if (key == B_ESC)
		ft_close(data);
	else if (key == B_NUM_4)
		ft_turn_player(data, -1);
	else if (key == B_NUM_6)
		ft_turn_player(data, 1);
	else if (key == B_W)
		ft_player_step_forward(data, 1);
	else if (key == B_S)
		ft_player_step_forward(data, -1);
	ft_printf("key=%d\n", key);
	return (1);
}
