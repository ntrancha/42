/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:42:02 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/15 15:13:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFF        1000

int				get_next_line_count(const char *all)
{
	int			index;

	index = 0;
	while (all[index] != '\n' && all[index])
	{
		index++;
	}
	if (!all[index] && !index && all[0] != '\n')
		return (-1);
	return (index);
}

int				get_next_line_split(char *all, char **line)
{
	int			s;

	s = get_next_line_count(all);
	ft_strdel(line);
	*line = ft_strsub(all, 0, s);
	return (s);
}

int				get_next_line_read(int const fd, char **line, char **all)
{
	char		*tmp;
	int			ret;

	ret = BUFF;
	tmp = NULL;
	while (ret)
	{
		ft_strdel(line);
		*line = ft_strnew(BUFF + 1);
		ret = read(fd, *line, BUFF);
		if (ret == -1 || *line == NULL)
			return (-1);
		tmp = ft_strnew(ft_strlen(*all) + BUFF + 1);
		ft_strcpy(tmp, *all);
		ft_strdel(all);
		tmp = ft_strncat(tmp, *line, ret);
		*all = ft_strnew(ft_strlen(tmp) + BUFF + 2);
		ft_strcpy(*all, tmp);
		ft_strdel(&tmp);
	}
	ft_strdel(line);
	return (0);
}

void			get_next_line_debug(char **str)
{
	int			size;
	char		*tmp;

	tmp = *str;
	size = ft_strlen(tmp);
	if (tmp[size] == '\0' && tmp[size - 1] == '\n')
	{
		tmp[size] = '\n';
		tmp[size + 1] = '\0';
	}
}

int				get_next_line(int const fd, char **line)
{
	static char	*all[10];
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFF < 1)
		return (-1);
	ft_strdel(line);
	*line = ft_strnew(BUFF + 1);
	if (!all[fd])
	{
		all[fd] = ft_strnew(BUFF + 1);
		ret = get_next_line_read(fd, line, &all[fd]);
		//get_next_line_debug(&all[fd]);
		if (ret == -1)
			return (ret);
	}
	ret = get_next_line_split(all[fd], line);
	if (ret == -1)
		return (0);
	tmp = ft_strsub(all[fd], ret + 1, ft_strlen(all[fd]));
	ft_strdel(&all[fd]);
	all[fd] = ft_strnew(ft_strlen(tmp) + 1);
	ft_strcpy(all[fd], tmp);
	ft_strdel(&tmp);
	return (1);
}

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;

	line = NULL;
	line = ft_strnew(BUFF + 1);
	fd = open("file.txt", O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret)
		{
			ft_putstr(line);
			ft_putstr("\n");
		}
	}
	ft_strdel(&line);
	close(fd);
	return (0);
}
