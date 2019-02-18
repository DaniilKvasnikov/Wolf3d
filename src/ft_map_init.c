/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 07:41:55 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/18 21:54:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_map_init(t_data *data, char *filename)
{
	char		*str;
	int			max;

	str = ft_get_file_str(filename);
	max = 1;
	data->mydata->map.map = NULL;
	if (str != NULL && ft_check_str(str, &max))
	{
		if ((data->mydata->map.size = ft_get_size(str)) != NULL)
		{
			if ((data->mydata->map.map =
					(int *)malloc(
						sizeof(int) *
						(data->mydata->map.size[0]) *
						(data->mydata->map.size[1])))
				!= NULL)
			{
				ft_create_map(data, str, max);
			}
		}
		else
			ft_putendl("error whith string in file");
	}
	ft_free_ptr(str);
}
