/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:37:39 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 16:48:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	--argc;
	++argv;
	if (argc >= 1)
		ft_open_win(argv[0], argc, argv);
	else
	ft_printf("./wolf3d [file_name] [flags]\nflags:\
	-f туман войны\n\
	-m вывод карты\n\
	-c текстуры с файла\n");
	return (0);
}
