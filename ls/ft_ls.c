/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:09:12 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 10:40:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "param.h"
#include "list.h"
#include "list_del.h"
#include "dos.h"
#include "test.h"
#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>

int         ft_ls_testdir(char *str)
{
    DIR     *ret;

        ret = opendir(str);
        if (ret)
        {
            closedir(ret);
            return (1);
        }
        ft_putstr(str);
        ft_putstr(": Aucun fichier ou dossier de ce type\n");
    return (0);
}

int			ft_ls_arg_option(t_param *param, int argc, char **argv)
{
	int		count;

	count = 0;
	while (++count < argc && argv[count][0] == '-')
    {
		if (ft_ls_param(argv[count]) == 1)
	        if (ft_ls_paramset(param, argv[count]))
            	return (-1);
    }
	count--;
	param->prog_name = malloc(sizeof(char) * (ft_strlen(argv[0]) + 1));
	ft_strcpy(param->prog_name, argv[0]);
	return (count);
}

t_dos		*ft_ls_arg(t_param *param, int argc, char **argv)
{
	int		count;
    t_dos   *dos;

	dos = NULL;
    param->m++;
	count = ft_ls_arg_option(param, argc, argv);
	if (count == -1)
	{
		param->m = -1;
		return (NULL);
	}
	while (++count < argc)
    {
        param->m++;
            dos = ft_list_dos_new(argv[count], dos);
			if (dos == NULL)
			{
				param->m = -1;
				return (NULL);
			}
    }
	return (dos);
}

int		main(int argc, char **argv)
{
	t_param *param;
    t_dos   *dos;
    t_dos   *file;
	t_llist	*list;

    param = ft_ls_param_new();
	if (param == NULL)
		return (-1);
	dos = ft_ls_arg(param, argc, argv);
	file = ft_list_dos_create("?");
	list = NULL;
	if (dos == NULL && param->m == -1)
	{
		param = ft_ls_param_del(param);
		return (-1);
	}
	if (dos == NULL)
		dos = ft_list_dos_new(".", dos);
	if (dos == NULL)
		return (-1);
	ft_list_dos_sort(&dos, param->r);
	ft_ls_test_dos(&dos, &file, param);
	ft_list_dos_del(&file);
	ft_ls_display_file(&file, param);
	while (dos != NULL)
	{
		list = ft_list_create(dos->str);
		if ((param->m > 1 || param->f > 0) && param->recursive == 0)
		{
			ft_putstr(list->path);
			ft_putstr(":\n");
		}
		while (list != NULL)
		{
			ft_list_sort_name(list, param->r);
			if (ft_ls_recup(list, param) == 0)
				return (-1);
			if (param->t == 1)
				ft_list_sort_mtime(list, param->r);
			ft_ls_display(list, param);
			if (!(param->recursive == 1 || param->r == -1))
				ft_list_sort_path(&list, param->r);
			list = ft_list_del_path(list);
			if (list && (param->recursive == 1 || param->r == -1))
				ft_list_sort_path(&list, param->r);
			if (list)
				ft_putstr("\n");
		}
		ft_list_del(list);
		ft_list_dos_del(&dos);
		if (dos != NULL)
			ft_putstr("\n");
	}
	dos = ft_list_dos_free(&dos);
	dos = ft_list_dos_free(&file);
	param = ft_ls_param_del(param);
	return (0);
}
