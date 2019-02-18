/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:16:54 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/18 22:02:56 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_getsize(char **str)
{
	int size;

	size = -1;
	while (str[++size] != NULL)
		;
	return (size);
}

int			ft_check_str_int(char **str, int *max)
{
	int		index;
	int		par;

	index = -1;
	while (str[++index] != NULL)
	{
		par = ft_atoi(str[index]);
		if (par == 0)
			if (ft_strlen(str[index]) != 1 || str[index][0] != '0')
				return (1);
		par = abs(par);
		if (par > *max)
			*max = par;
	}
	return (0);
}

int			ft_check_str(char *str, int *max)
{
	char	**res;
	char	**ints;
	int		index;
	int		size;
	int		cmp;

	res = ft_strsplit(str, '\n');
	index = -1;
	size = 0;
	cmp = 1;
	while (res[++index] != NULL)
	{
		ints = ft_strsplit(res[index], ' ');
		if (size == 0)
			size = ft_getsize(ints);
		if (size != ft_getsize(ints) || ft_check_str_int(ints, max))
			cmp = 0;
		ft_free(ints);
	}
	ft_free(res);
	return (cmp);
}

int			*ft_get_size(char *str)
{
	int		*size;
	char	**res;
	char	**ints;

	if ((size = (int *)malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	res = ft_strsplit(str, '\n');
	ints = ft_strsplit(*res, ' ');
	if (res != NULL && ints != NULL)
	{
		size[0] = ft_getsize(res);
		size[1] = ft_getsize(ints);
	}
	else
	{
		ft_free_ptr(size);
		size = NULL;
	}
	ft_free(res);
	ft_free(ints);
	return (size);
}

void		ft_create_map(t_data *data, char *str, int max)
{
	char	**res;
	char	**ints;
	int		index;
	int		index1;
	int		index2;

	res = ft_strsplit(str, '\n');
	index = -1;
	index1 = -1;
	while (res[++index1] != NULL)
	{
		ints = ft_strsplit(res[index1], ' ');
		index2 = -1;
		while (ints[++index2] != NULL)
		{
			data->mydata->map.map[++index] = ft_atoi(ints[index2]) / (float)max * MAX_H;
		}
		ft_free(ints);
	}
	ft_free(res);
}
