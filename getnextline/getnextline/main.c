/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:42:02 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/12 14:35:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#define	BUFF		1

int					taille(char *line)
{
	int				size;
	int				test;

	size = 0;
	test = 0;
	while (line[size] && !test)
	{
		if (line[size] == '\n')
			test = 1;
		size++;
	}
	return (size * test);
}

int					get_next_line(int const fd, char ** line)
{
	static char		*ptr;
	static int		seek;
	char			*tmp;
	int				ret;
	int				ret2;

	if (seek == 0)
	{
		ft_putstr("NEW\n");
		ptr = (char *)ft_strnew(BUFF + 1);
		ret = read(fd, ptr, BUFF);
		seek += BUFF;
		ptr[BUFF] = '\0';
		*line = ptr;
		ft_putnbr(taille(*line));
	}
	else
	{
		tmp = ft_strnew(ft_strlen(*line) + BUFF + 1);
		tmp = (char *)ft_strcat(tmp, *line);
		seek += BUFF;
		//lseek(fd, 0, SEEK_SET);
		ret = read(fd, ptr, BUFF);
		ptr[BUFF] = '\0';
		*line = (char *)ft_strcat(tmp, ptr);
		//ft_putstr("LINE ==");
		ft_putstr(*line);
		ft_putstr("\n");
		ft_putstr("retour ligne ==");
		ft_putnbr(taille(*line));
		ft_putstr("\n");
	}
}

int					main(void)
{
	char		*line;
	int			fd;

	fd = open("file", O_RDONLY);
	line = NULL;
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	get_next_line(fd, &line);
	ft_putstr("RES  ==");
	if (*line)
		ft_putstr(line);
	ft_putstr("\n");
	return (0);
}
