/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 01:32:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/19 02:04:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	load_textures(t_data *data)
{
	int		w;
	int		h;

	w = 64;
	h = 64;
	data->mydata->texture[0].image = mlx_xpm_file_to_image(
		data->mlx_ptr, "textures/stone.xpm", &w, &h);
	data->mydata->texture[0].data = (int *)mlx_get_data_addr(
		data->mydata->texture[0].image, &data->mydata->texture[0].bpp,
		&data->mydata->texture[0].sizeline, &data->mydata->texture[0].end);
}
