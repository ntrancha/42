/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:09:54 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 10:26:20 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <libft.h>
#include "dos.h"
#include "recup.h"
#include "param.h"
#include "return.h"

void		ft_ls_error(char *str, t_param *param)
{
	ft_putstr(param->prog_name);
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr(strerror( errno ));
	ft_putstr("\n");
}

int			ft_ls_test_dir(char *str)
{
	DIR		*dir;
	int		ret;

	dir = opendir(str);
	if (dir != NULL)
	{
		closedir(dir);
		return (1);
	}
	ret = 0;
	return (ret);
}


int			ft_ls_test_file_next(char *path, char *file)
{
	t_dir	*files;
	DIR		*dir;
	t_stat	s;

	dir = opendir(path);
	if (dir != NULL)
	{
		while (files = readdir(dir))
		{
			if (ft_strcmp(files->d_name, file) == 0)
			{
				lstat(files->d_name, &s);
				closedir(dir);
				return (1);
			}
		}
		closedir(dir);
	}
	return (-1);
}

int			ft_ls_test_file(char *str)
{
	int		ret;
	char	*path;
	char	*file;

	path = ft_ls_return_path(str);
	file = ft_ls_return_file(str);
	ret = ft_ls_test_file_next(path, file);
	ft_strdel(&path);
	ft_strdel(&file);
	return (ret);
}

int			ft_ls_test_dos_next(t_dos *tmp, t_dos **file, t_param *param)
{
	if (ft_ls_test_file(tmp->str) != -1)
	{
		param->f++;
		*file = ft_list_dos_new(tmp->str, *file);
		return (1);
	}
	ft_ls_error(tmp->str, param);
	return (0);
}

int			ft_ls_test_dos(t_dos **dos, t_dos **file, t_param *param)
{
	t_dos	*prev;
	t_dos	*tmp;

	prev = NULL;
	tmp = *dos;

	while (tmp != NULL)
	{
		if (ft_ls_test_dir(tmp->str) == 0)
		{
			ft_ls_test_dos_next(tmp, file, param);
			if (prev != NULL)
				prev->next = tmp->next;
			else
				*dos = tmp->next;
			ft_strdel(&tmp->str);
			free(tmp);
			param->m--;
			return (ft_ls_test_dos(dos, file, param));
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}
