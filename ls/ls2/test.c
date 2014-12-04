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

char		*ft_ls_return_file(char *str)
{
	int		index;
	char	*ret;

	index = ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == '/')
			return (ft_strsub(str, index + 1, (ft_strlen(str) - index)));
		index--;
	}
	return (ft_strdup(str));
}

char		*ft_ls_return_path(char *str)
{
	char	*ret;
	int		index;
	int		test = 0;

	index = ft_strlen(str);
	while (index-- >= 0)
	{
		if (str[index] == '/')
			test = 1;
	}
	if (test == 0)
	{
		ret = ft_strnew(2);
		ret[0] = '.';
		ret[1] = '\0';
		return (ret);
	}
	index = ft_strlen(str);
	ret = ft_strdup(str);
	while (index-- > 1)
	{
		if (ret[index] == '/')
		{
			ret[index] = '\0';
			index = 0;
		}
	}
	return (ret);
}



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
	ret = 0;//ft_ls_test_file(str, param);
	return (ret);
}

int			ft_ls_return_rights(t_stat m)
{
	int 	ret;

	ret = 0;
	if ((m.st_mode & S_IRUSR) != 0)
		ret += 400;
    if ((m.st_mode & S_IWUSR) != 0)
		ret += 200;
    if ((m.st_mode & S_IXUSR) != 0)
		ret += 100;
    if ((m.st_mode & S_IRGRP) != 0)
		ret += 40;
    if ((m.st_mode & S_IWGRP) != 0)
		ret += 20;
    if ((m.st_mode & S_IXGRP) != 0)
		ret += 10;
    if ((m.st_mode & S_IROTH) != 0)
		ret += 4;
    if ((m.st_mode & S_IWOTH) != 0)
		ret += 2;
    if ((m.st_mode & S_IXOTH) != 0)
		ret += 1;
	if (S_ISDIR(m.st_mode))
		return (-1);
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
				return (ft_ls_return_rights(s));
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
