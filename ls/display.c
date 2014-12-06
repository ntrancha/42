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

#include "list.h"
#include "dos.h"
#include "param.h"
#include "print.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include "recup.h"

void			ft_ls_new_path(char **dst, char *str1, char *str2)
{
	int			size;

	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	ft_strdel(dst);
	*dst = (char*)malloc(sizeof(char) * size);
	ft_strcpy(*dst, str1);
	ft_strcat(*dst, str2);
}

void			ft_ls_display_std(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	
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

void			ft_ls_display_list(t_llist *list, t_param *param, t_list *fichier)
{
	t_stat  s;

    lstat(fichier->str,&s);
	print_rights(s.st_mode);
	ft_putstr(" ");
	ft_ls_display_std(fichier->str);
}

void			ft_ls_display_next(t_llist *list, t_param *param, t_list *fichier)
{
	char		*str;
	char		*str2;

	str2 = NULL;
	str = NULL;
	while (fichier)
	{
		if (fichier->str[0] != '.' || param->a)
		{
			if (ft_strcmp(fichier->str, list->path) != 0)
			{
				if (param->l == 0)
					ft_ls_display_std(fichier->str);
				else
					ft_ls_display_list(list, param, fichier);
			}
			if (fichier->stats->type == 'd' && param->recursive == 1)
			{
				if (ft_strcmp(fichier->str, "..") != 0)
					if (ft_strcmp(fichier->str, ".") != 0)
					{
						if (ft_strcmp(list->path, "/") != 0)
							ft_ls_new_path(&str2, list->path, "/");
						else
							ft_ls_new_path(&str2, list->path, "");
						ft_ls_new_path(&str, str2, fichier->str);
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
		if (param->t)
			ft_list_sort_mtime(list, 1);
		else
			ft_list_sort_name(list, 1);
		if (param->r == 1)
			fichier = list->start;
		else
			fichier = list->end;
		if (param->recursive == 1)
		{
			ft_putstr(list->path);
			ft_putstr(":\n");
		}
		if (ft_ls_test_dir(list->path, param) == 0)
			ft_ls_error(list->path, param);
		else
			ft_ls_display_next(list, param, fichier);
	}
}
