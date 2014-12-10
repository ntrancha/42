/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 08:45:37 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 11:26:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <libft.h>
#include "display.h"
#include "display_list.h"
#include "print.h"
#include "print_size.h"
#include "list.h"
#include "list_sort.h"
#include "list_sort_time.h"
#include "param.h"
#include "size_max_nbr.h"
#include "size_max_str.h"
#include "extra.h"
#include "recup.h"
#include "return.h"
#include "test.h"
#include "error.h"
#include "print.h"
#include "date.h"
#include <time.h>
#include "option.h"

static void		recup_max_size(t_llist *root, t_param *param)
{
	root->size_user = user_max_len(root, 0, 0, param);
	root->size_group = group_max_len(root, 0, 0, param);
	root->size_minor = minor_max_len(root, 0, param);
	root->size_major = major_max_len(root, 0, param);
	root->size_link = links_max_len(root, 0, param);
	root->size_size = size_max_len(root, 0, param);
	root->size_date = date_max_len(root, 0, param);
	root->size_year = year_max_len(root, 0, param);
}

static char		*add_path(t_llist *root, char *file)
{
	char		*str;
	char		*str2;

	str2 = NULL;
	str = NULL;
	if (ft_strcmp(file, "..") != 0)
		if (ft_strcmp(file, ".") != 0)
		{
			if (ft_strcmp(root->path, "/") != 0)
				ft_ls_return_new_path(&str2, root->path, "/");
			else
				ft_ls_return_new_path(&str2, root->path, "");
			if (str2 == NULL)
				return (NULL);
			ft_ls_return_new_path(&str, str2, file);
			if (str == NULL)
				return (NULL);
			ft_strdel(&str2);
			root = ft_list_add_dir(root, str);
			ft_strdel(&str);
		}
	return (file);
}

static void		display_param(t_param *param, t_list *file, t_llist *root)
{
	if (param->inode == 1)
		option_inode(file->str, root->path);
	if (param->l == 0 && param->commas == 0)
		display_std(file->str, param, root);
	else if (param->commas == 1 && param->l == 0)
		option_commas(file, param, file->str);
	else
		display_list(file, root, param);
}

static t_list	*display_next(t_llist *root, t_param *param, t_list *file)
{
	while (file)
	{
		if (file_ok(file, param) == 1)
		{
			if (ft_strcmp(file->str, root->path) != 0)
			 	display_param(param, file, root);
			if (file->stats->type == 'd' && param->recursive == 1)
				if (add_path(root, file->str) == NULL)
					return (NULL);
		}
		file = file->next;
	}
	return (NULL);
}

void			display(t_llist *root, t_param *param)
{
	t_list		*file;

	if (root)
	{
		file = root->start;
		if (param->recursive == 1)
		{
			ft_putstr(root->path);
			ft_putstr(":\n");
		}
		if (ft_ls_test_dir(root->path) == 0)
			ft_ls_error(root->path, param);
		else
		{
			if (param->l == 1)
			{
				recup_max_size(root, param);
				ft_putstr("total ");
				ft_putnbr(param->list_total);
				ft_putstr("\n");
			}
			display_next(root, param, file);
		}
	}
}
