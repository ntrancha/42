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

int				ft_ls_display_std(char *file, t_param *param, t_llist *root)
{
	t_stat  	s;
	char		*str;
	char		*tmp;

	tmp = ft_strjoin(root->path, "/");
	str = ft_strjoin(tmp, file);
	ft_strdel(&tmp);
	ft_putstr(file);
    if (lstat(str, &s) != 0)
    	if (stat(str, &s) != 0)
			return (-1);
	if (param->p == 1 && S_ISDIR(s.st_mode) && param->carac == 0)
		ft_putstr("/");
	if (param->carac == 1)
		option_carac(s);
	ft_putstr("\n");
	ft_strdel(&str);
	return (0);
}

void			ft_ls_display_file(t_dos **file, t_param *param)
{
	while (*file != NULL)
    {
        ft_putstr((*file)->str);
        ft_putstr("\n");
        ft_list_dos_del(file);
        if (*file == NULL && param->m > 0)
            ft_putstr("\n");
    }
}

void			ft_ls_recup_size(t_llist *root, t_param *param)
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

int				ft_ls_display_list(t_list *fichier, t_llist *root, t_param *param)
{
	t_stat  	s;
	char		*str;
	char		*tmp;

	tmp = ft_strjoin(root->path, "/");
	str = ft_strjoin(tmp, fichier->str);
	ft_strdel(&tmp);
    if (lstat(str, &s) != 0)
    	if (stat(str, &s) != 0)
			return (-1);
	print_rights(s.st_mode);
	print_link(root, s);
	print_users(root, s);
	print_minor(root, s, fichier);
	if (param->u == 1)
		print_size_atime(root, s);
	else if (param->c == 1)
		print_size_ctime(root, s);
	else
		print_size_mtime(root, s);
	ft_ls_display_std(fichier->str, param, root);
	ft_strdel(&str);
	return (0);
}

void			ft_ls_display_next(t_llist *list, t_param *param, t_list *fichier)
{
	char		*str;
	char		*str2;

	str2 = NULL;
	str = NULL;
	while (fichier)
	{
		if (file_get(fichier, param) == 1)
		{
			if (ft_strcmp(fichier->str, list->path) != 0)
			{
				if (param->inode == 1)
					option_inode(fichier->str, list->path);
				if (param->l == 0 && param->commas == 0)
					ft_ls_display_std(fichier->str, param, list);
				else if (param->commas == 1 && param->l == 0)
					option_commas(fichier, param, fichier->str);
				else
					ft_ls_display_list(fichier, list, param);
			}
			if (fichier->stats->type == 'd' && param->recursive == 1)
			{
				if (ft_strcmp(fichier->str, "..") != 0)
					if (ft_strcmp(fichier->str, ".") != 0)
					{
						if (ft_strcmp(list->path, "/") != 0)
							ft_ls_return_new_path(&str2, list->path, "/");
						else
							ft_ls_return_new_path(&str2, list->path, "");
						ft_ls_return_new_path(&str, str2, fichier->str);
						ft_strdel(&str2);
						list = ft_list_add_dir(list, str);
						ft_strdel(&str);
					}
			}
		}
		if (param->r == 1)
			fichier = fichier->next;
		else
			fichier = fichier->previous;
	}
}

void		ft_ls_display(t_llist *list, t_param *param)
{
	t_list	*fichier;

	if (list)
	{
		if (param->l == 1)
			ft_ls_recup_size(list, param);
		//ft_list_sort_name(list, 1);
		//if (param->t == 1)
		//	ft_list_sort_mtime(list, param->r);
		//else if (param->u == 1)
		//	ft_list_sort_atime(list, param->r);
		//if (param->s == 1)
        //    ft_list_sort_size(list, param->r);
		if (param->r == 1)
			fichier = list->start;
		else
			fichier = list->end;
		if (param->recursive == 1)
		{
			ft_putstr(list->path);
			ft_putstr(":\n");
		}
		if (ft_ls_test_dir(list->path) == 0)
			ft_ls_error(list->path, param);
		else
			ft_ls_display_next(list, param, fichier);
	}
}
