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

#include <dirent.h>
#include <stdlib.h>
#include <libft.h>
#include "param.h"
#include "param_set.h"
#include "list.h"
#include "list_sort.h"
#include "list_sort_path.h"
#include "list_sort_time.h"
#include "list_del.h"
#include "dos.h"
#include "test.h"
#include "recup.h"
#include "display.h"
#include "ft_ls.h"
#include "print.h"
#include "print_size.h"

static int		ft_ls_arg_option(t_param *param, int argc, char **argv)
{
	int			count;

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

static t_dos	*ft_ls_arg(t_param *param, int argc, char **argv)
{
	int			count;
    t_dos   	*dos;

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

static t_llist	*ft_ls3(t_llist *list, t_param *param)
{
	while (list != NULL)
	{
		if (ft_ls_recup(list, param) == 0)
			return (NULL);
		ft_list_sort_name(list, param->r);
		if (param->t == 1)
			ft_list_sort_mtime(list, param->r);
		if (param->u == 1)
			ft_list_sort_atime(list, param->r);
		if (param->c == 1)
			ft_list_sort_ctime(list, param->r);
		if (param->s == 1)
			ft_list_sort_size(list, param->r);
		ft_ls_display(list, param);
		if (!(param->recursive == 1 || param->r == -1))
			ft_list_sort_path(&list, param->r);
		list = ft_list_del_path(list);
		if (list && (param->recursive == 1 || param->r == -1))
			ft_list_sort_path(&list, param->r);
		if (list)
			ft_putstr("\n");
	}
	return (list);
}

static int		ft_ls2(t_dos *dos, t_llist *list, t_param *param, t_dos *file)
{
	while (dos != NULL)
	{
		list = ft_list_create(dos->str);
		if ((param->m > 1 || param->f > 0) && param->recursive == 0)
		{
			ft_putstr(list->path);
			ft_putstr(":\n");
		}
		list = ft_ls3(list, param);
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

static int		ft_ls(int argc, char **argv)
{
	t_param 	*param;
    t_dos   	*dos;
    t_dos   	*file;
	t_llist		*list;

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
	return (ft_ls2(dos, list, param, file));
}

int		main(int argc, char **argv)
{
	return (ft_ls(argc, argv));
}
