/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 08:05:35 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 10:37:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>
#include <libft.h>
#include "list.h"
#include "recup.h"
#include "return.h"
#include "test.h"
#include "param.h"

void		ft_ls_recup_mode(t_llist *list, t_dir *file)
{
	if (file->d_type == DT_BLK)
		list->end->stats->type = 'b';
	if (file->d_type == DT_CHR)
		list->end->stats->type = 'c';
	if (file->d_type == DT_DIR)
		list->end->stats->type = 'd';
	if (file->d_type == DT_FIFO)
		list->end->stats->type = 'f';
	if (file->d_type == DT_LNK)
		list->end->stats->type = 'l';
	if (file->d_type == DT_REG)
		list->end->stats->type = 'r';
	if (file->d_type == DT_SOCK)
		list->end->stats->type = 's';
	if (file->d_type == DT_UNKNOWN)
		list->end->stats->type = 'u';
}

t_llist		*ft_ls_recup2(t_llist *list, t_stat s, t_dir *file)
{
	int		a;
	t_pass	*pass2;

	pass2 = getpwuid(s.st_gid);
	if (pass2 && !ft_strcmp(file->d_name, ".") && !ft_strcmp(file->d_name, ".."))
	{
		a = ft_strlen(pass2->pw_name);
		list->end->stats->group = malloc(sizeof(char) * a + 1);
		if (list->end->stats->group == NULL)
			return (NULL);
		ft_strcpy(list->end->stats->group, pass2->pw_name);
	}
	if ((s.st_mode & S_IFMT) == S_IFDIR)
		list->end->stats->mode = 1;
	return (list);
}

t_llist		*ft_ls_recup_stats(t_llist *list, t_dir *file)
{
	int		a;
	t_stat	s;
	t_pass	*pass;

	if (lstat(file->d_name,&s) != 0)
		if (stat(file->d_name,&s) != 0)
			return (NULL);
	if (ft_ls_return_rights(file) < 400)
			return (NULL);
	pass = getpwuid(s.st_uid);
	if (pass)
	{
		a = ft_strlen(pass->pw_name);
		list->end->stats->user = malloc(sizeof(char) * a + 1);
		if (list->end->stats->user == NULL)
			return (NULL);
		ft_strcpy(list->end->stats->user, pass->pw_name);
	}
	return (ft_ls_recup2(list, s, file));
}

void			ft_ls_recup_file(t_llist *list, t_param *param, t_dir *file)
{
	t_stat	s;

	if (param->t == 1 || param->l == 1)
	{
		if (lstat(file->d_name,&s) == 0)
		{
			list = ft_list_add(list, file->d_name, (int)s.st_size);
			list->end->time->atime = s.st_atime;
			list->end->time->mtime = s.st_mtime;
			list->end->time->ctime = s.st_ctime;
		}
		else
			list = ft_list_add(list, file->d_name, 0);
	}
	else
		list = ft_list_add(list, file->d_name, 0);
	if (param->l == 1)
		ft_ls_recup_stats(list, file);
	ft_ls_recup_mode(list, file);
}

int                 ft_ls_recup(t_llist *list, t_param *param)
{
	DIR		*dir;
	t_dir	*file;

	if (!list)
		return (0);
	if (ft_ls_test_dir(list->path) == 0)
		return (1);
	dir = opendir(list->path);
	if (!dir)
		return (0);
	while ((file = readdir(dir)))
		ft_ls_recup_file(list, param, file);
	closedir(dir);
	return (1);
}
