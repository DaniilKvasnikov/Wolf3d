/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:36:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 18:08:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				ft_close(t_data *data)
{
	ft_free_ptr(data->mydata->map.map);
	ft_free_ptr(data->mydata->map.size);
	exit(0);
	return (0);
}
