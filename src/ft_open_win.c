/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 07:03:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/27 14:10:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int
	in_map
	(t_data *data)
{
	int	index;
	int	x;
	int	y;

	x = data->mydata->map.size[0];
	y = data->mydata->map.size[1];
	if (x < 3 || y < 3)
		return (1);
	if ((data->mydata->posx <= 1.0) || (data->mydata->posy <= 1.0) ||
	(data->mydata->posx >= (x - 1)) || (data->mydata->posy >= (y - 1)))
		return (1);
	if (data->mydata->map.map[(int)
	(data->mydata->posx + data->mydata->posy * y)] != 0)
		return (1);
	index = -1;
	while (++index < y)
		if ((data->mydata->map.map[index] == 0) ||
		(data->mydata->map.map[(int)(index + (x - 1) * y)] == 0))
			return (1);
	index = -1;
	while (++index < x)
		if ((data->mydata->map.map[0 + index * y] == 0) ||
			(data->mydata->map.map[x - 1 + index * y] == 0))
			return (1);
	return (0);
}

void		ft_start_game(t_data *data, char *str, int argc, char **argv)
{
	data->mydata = (t_mydata *)malloc(sizeof(t_mydata));
	data->mydata->posx = 1.2;
	data->mydata->posy = 1.2;
	data->mydata->dirx = 1;
	data->mydata->diry = 0;
	data->mydata->planex = 0;
	data->mydata->planey = -0.66;
	data->mydata->move = 0;
	data->mydata->turn = 0;
	data->mydata->run = 1;
	data->mydata->argc = argc;
	data->mydata->argv = argv;
	ft_map_init(data, str);
	load_textures(data);
	if (in_map(data))
	{
		ft_putendl_fd("Map error", 2);
		ft_close(data);
	}
}

void		ft_open_win(char *str, int argc, char **argv)
{
	t_data	data;

	if (((data.mlx_ptr = mlx_init()) == 0) ||
		((data.mlx_win =
		mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, str)) == NULL) ||
		((data.img = (t_img *)malloc(sizeof(t_img))) == NULL) ||
		((data.mydata = (t_mydata *)malloc(sizeof(t_mydata))) == NULL))
		return ;
	ft_start_game(&data, str, argc, argv);
	mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop_hook(data.mlx_ptr, ft_draw, &data);
	mlx_hook(data.mlx_win, 2, 1L << 2, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 3, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, ft_close, &data);
	data.img->img_ptr = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
	data.img->data = (int *)mlx_get_data_addr(data.img->img_ptr,
		&data.img->bpp, &data.img->size_l, &data.img->endian);
	mlx_loop(data.mlx_ptr);
}
