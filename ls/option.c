/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 21:13:44 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/07 21:13:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <libft.h>
#include <stdlib.h>
#include "recup.h"
#include "option.h"
#include <sys/ioctl.h>

void		option_carac(t_stat s)
{
	if (S_ISDIR(s.st_mode))
		ft_putchar('/');
	else if (S_ISLNK(s.st_mode))
        ft_putchar('@');
	else if (S_ISFIFO(s.st_mode))
        ft_putchar('|');
	else if ((s.st_mode & S_IXUSR) != 0)
		ft_putchar('*');
}

static void	option_list_next(mode_t m)
{
    if ((m & S_IXGRP) != 0)
		ft_putchar('x');
	else
		ft_putchar('-');
    if ((m & S_IROTH) != 0)
		ft_putchar('r');
	else
		ft_putchar('-');
    if ((m & S_IWOTH) != 0)
		ft_putchar('w');
	else
		ft_putchar('-');
    if ((m & S_IXOTH) != 0)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		option_list(mode_t m)
{
	if ((m & S_IRUSR) != 0)
		ft_putchar('r');
	else
		ft_putchar('-');
    if ((m & S_IWUSR) != 0)
		ft_putchar('w');
	else
		ft_putchar('-');
    if ((m & S_IXUSR) != 0)
		ft_putchar('x');
	else
		ft_putchar('-');
    if ((m & S_IRGRP) != 0)
		ft_putchar('r');
	else
		ft_putchar('-');
    if ((m & S_IWGRP) != 0)
		ft_putchar('w');
	else
		ft_putchar('-');
	option_list_next(m);
}

int			option_inode(char *file, char*path)
{
    t_stat      s;
    char        *str;
    char        *tmp;

    tmp = ft_strjoin(path, "/");
    str = ft_strjoin(tmp, file);
    ft_strdel(&tmp);
    if (lstat(str, &s) != 0)
        if (stat(str, &s) != 0)
            return (-1);
	ft_putnbr(s.st_ino);
    ft_strdel(&str);
	ft_putchar(' ');
	return (0);
}

void	option_commas(t_list *file, t_param *param, char *str)
{
	win			window;
	int			col;
	int		size;

    ioctl(0, TIOCGWINSZ, &window);
	col = window.ws_col;
	size = ft_strlen(str) + 2;
	if (param->total + size > col)
	{
		param->total = 0;
		ft_putchar('\n');
	}
	param->total += size;
	ft_putstr(str);
	if (file->next != NULL)
	{
		ft_putstr(",");
		if ((param->total + (int)ft_strlen(file->next->str) + 2) <= col)
			ft_putstr(" ");
	}
	else
		ft_putchar('\n');
}
