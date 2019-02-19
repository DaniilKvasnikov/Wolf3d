/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 01:32:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/19 05:39:09 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		load_textures2(t_data *data)
{
	int		w;
	int		h;

	w = 64;
	h = 64;
	data->mydata->texture[3].data =
	(int *)mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/eagle.xpm", &w, &h), &data->mydata->texture[3].bpp,
	&data->mydata->texture[3].sizeline, &data->mydata->texture[3].end);
	data->mydata->texture[4].data =
	(int *)mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/redbrick.xpm", &w, &h), &data->mydata->texture[4].bpp,
	&data->mydata->texture[4].sizeline, &data->mydata->texture[4].end);
}

void		load_textures(t_data *data)
{
	int		w;
	int		h;

	w = 64;
	h = 64;
	data->mydata->texture[0].data =
	(int *)mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/wood.xpm", &w, &h), &data->mydata->texture[0].bpp,
	&data->mydata->texture[0].sizeline, &data->mydata->texture[0].end);
	data->mydata->texture[1].data =
	(int *)mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/purplestone.xpm", &w, &h), &data->mydata->texture[1].bpp,
	&data->mydata->texture[1].sizeline, &data->mydata->texture[1].end);
	data->mydata->texture[2].data =
	(int *)mlx_get_data_addr(mlx_xpm_file_to_image(data->mlx_ptr,
	"textures/mossy.xpm", &w, &h), &data->mydata->texture[2].bpp,
	&data->mydata->texture[2].sizeline, &data->mydata->texture[2].end);
	load_textures2(data);
}
