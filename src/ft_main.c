/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:37:39 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/20 19:19:37 by rrhaenys         ###   ########.fr       */
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
		ft_printf("%s\n%s\n\t%s\n\t%s\n\t%s\n\t%s\n",
		"./wolf3d [file_name] [flags]",
		"flags:",
		"-f туман войны",
		"-m вывод карты",
		"-c текстуры из файла",
		"-k вывод кода клавиши");
	return (0);
}
