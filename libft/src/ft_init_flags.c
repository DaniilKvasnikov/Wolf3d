/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:14:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 11:07:53 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(t_spec *elem, char c)
{
	if (c == '-')
		return (elem->flag.minus = 1);
	else if (c == '+')
		return (elem->flag.plus = 1);
	else if (c == ' ')
		return (elem->flag.space = 1);
	else if (c == '0')
		return (elem->flag.zerro = 1);
	else if (c == '#')
		return (elem->flag.sharp = 1);
	return (0);
}

char	*get_flags(t_spec *elem, char *str)
{
	int	index;

	index = 0;
	while (is_flag(elem, str[index]))
		index++;
	return (&(str[index]));
}
