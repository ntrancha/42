/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:08:50 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/13 14:31:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#define BUFF        1

int				get_next_line_count(const char *all)
{
	int			index;

	index = 0;
	while (*all != '\n' && *all)
	{
		all++;
		index++;
	}
	if (*all == '\0')
		return (-1);
	return (index);
}

int				get_next_line_split(char *all, char **line)
{
	int			size;

	size = get_next_line_count(all);
	ft_strdel(line);
	*line = ft_strsub(all, 0, size);
	return (size);
}

int				get_next_line_read(int const fd, char ** line, char **all)
{
	char		*tmp;
	int			ret;

	ret = BUFF;
	tmp = NULL;
	while (ret)
	{
		ft_strdel(line);
		*line = ft_strnew(BUFF + 1);
		ret = read(fd, *line, BUFF);							// GET BUFF octet of fd on LINE
		if (ret == -1)
			return -1;
		line[BUFF] = '\0';
		tmp = ft_strnew(ft_strlen(*all) + BUFF + 1);			// New string for TMP  (size of ALL)
		ft_strcpy(tmp, *all);									// Copy ALL on TMP
		ft_strdel(all);											// Free ALL
		tmp = ft_strncat(tmp, *line, ret);						// Fusione TMP & LINE
		*all = ft_strnew(ft_strlen(tmp) + BUFF + 1);			// New string for ALL  (size of TMP)
		ft_strcpy(*all, tmp);									// Copy TMP on ALL
		ft_strdel(&tmp);										// Free TMP
	}
	ft_strdel(line);										// Free TMP
	return (0);
}

int				get_next_line(int const fd, char ** line)
{
	static char	*all[100];
	char		*tmp;
	int			ret;

	ft_strdel(line);
	*line = ft_strnew(BUFF + 1);
	if (fd < 0)
		return (-1);
	if (!all[fd])
	{
		all[fd] = ft_strnew(BUFF + 1);
		ret = get_next_line_read(fd, line, &all[fd]);
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

	//line = ft_strnew(BUFF + 1);
	line = NULL;
	fd = open("file", O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret)
			ft_putstr(line);
		if (ret)
			ft_putstr("\n");
	}
	//ret = get_next_line(fd, &line);
	//ft_putstr(line);
	ft_strdel(&line);											// Free LINE
	return (0);
}
