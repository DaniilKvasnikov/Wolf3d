/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:09:50 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/18 21:56:03 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdlib.h>

static char	*str_push(char *dest, char *src)
{
	char	*new;

	new = ft_strnew(ft_strlen(dest) + ft_strlen(src));
	ft_strcat(new, dest);
	ft_strcat(new, src);
	free(dest);
	return (new);
}

char		*ft_get_file_str(char *filename)
{
	char	*str;
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;

	PRIN_RET(((fd = open(filename, O_DIRECTORY)) > 0), "it's directory");
	close(fd);
	PRIN_RET(((fd = open(filename, O_RDONLY)) < 0), "file not found");
	PRIN_RET(((str = ft_strnew(0)) == 0), "string not found");
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = str_push(str, buf);
	}
	close(fd);
	return (str);
}
