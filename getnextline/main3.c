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

int				get_next_line_count(char *all, int count)
{
	int			index;

	while (count)
	{
		index = 0;
		while (*all != '\n' && *all)
		{
			all++;
			index++;
		}
		if (*all == '\0')
			return (-1);
		all++;
		count--;
	}
	return (index);
}

int				get_next_line_split(char *all, char **line, int count)
{
	int			size;
	int			tmp;
	int			index;

	index = 1;
	tmp = 0;
	size = get_next_line_count(all, count);
	ft_strdel(line);
	if (count > 1)
	{
		while (index + 1 <= count)
		{
			tmp += get_next_line_count(all, index) + 1;
			index++;
		}
	}
	*line = ft_strsub(all, tmp, size);
	return (size);
}

void			get_next_line_read(int const fd, char ** line, char **all)
{
	char		*tmp;
	int			ret;

	ret = BUFF;
	while (ret)
	{
		ret = read(fd, *line, BUFF);							// GET BUFF octet of fd on LINE
		line[BUFF] = '\0';
		tmp = ft_strnew(ft_strlen(*all) + BUFF + 1);			// New string for TMP  (size of ALL)
		ft_strcpy(tmp, *all);									// Copy ALL on TMP
		tmp = ft_strncat(tmp, *line, ret);						// Fusione TMP & LINE
		ft_strdel(all);											// Free ALL
		*all = ft_strnew(ft_strlen(tmp) + BUFF + 1);			// New string for ALL  (size of TMP)
		ft_strcpy(*all, tmp);									// Copy TMP on ALL
		ft_strdel(&tmp);										// Free TMP
	}
}

int				get_next_line(int const fd, char ** line)
{
	static char	*all;
	static int	count;

	if (count)
	{
		if (get_next_line_split(all, line, ++count) == -1)
		{
			ft_strdel(&all);									// Free TMP
			return (0);
		}
		return (1);
	}
	count = 1;
	all = ft_strnew(BUFF + 1);
	get_next_line_read(fd, line, &all);
	ft_strdel(line);											// Free LINE
	return (get_next_line_split(all, line, count));
}

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;

	line = ft_strnew(BUFF + 1);
	fd = open("file", O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		ft_putstr(line);
		if (ret)
			ft_putstr("\n");
	}
	ft_strdel(&line);											// Free LINE
	return (0);
}
