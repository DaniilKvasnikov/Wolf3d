/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:03:15 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 17:03:17 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_is_flag(t_data *data, char *str)
{
	int	index;

	index = -1;
	while (++index < (data->mydata->argc))
		if (ft_strcmp(data->mydata->argv[index], str) == 0)
			return (1);
	return (0);
}
