/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:08:50 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/12 15:44:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#define BUFF        12

int				main(void)
{
	char		*line;
	char		*all;
	char		*tmp;
	int			fd;
	int			ret;

	line = NULL;
	line = ft_strnew(BUFF + 1);
	all = ft_strnew(BUFF + 1);
	tmp = ft_strnew(BUFF + 1);
	ret = BUFF;
	fd = open("file", O_RDONLY);
	if (fd)
	{
		while (ret)
		{
			ret = read(fd, line, BUFF);
			line[BUFF] = '\0';
			tmp = ft_strnew(ft_strlen(all) + BUFF + 1);
			ft_strcpy(tmp, all);
			tmp = ft_strncat(tmp, line, ret);
			free(all);
			all = tmp;
		}
	}
	ft_putstr("\n");
	ft_putstr("=========================");
	ft_putstr("\n");
	ft_putstr(all);
	return (0);
}
