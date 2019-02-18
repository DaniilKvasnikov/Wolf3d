/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:04:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/18 22:01:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_free_ptr(void *data)
{
	if (data != NULL)
	{
		free(data);
	}
}

void		ft_free_date(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->mydata->map.map == NULL)
		return ;
	ft_free_ptr(data->mydata->map.map);
	ft_free_ptr(data->mydata->map.size);
//	ft_free_ptr(data->lines);
//	ft_free_ptr(data->mat);
//	ft_free_ptr(data->img.img_ptr);
//	ft_free_ptr(data->img.data);
}

void		ft_free(char **str)
{
	int		index;

	if (str == NULL)
		return ;
	index = -1;
	while (str[++index] != NULL)
	{
		free(str[index]);
	}
	free(str);
}
