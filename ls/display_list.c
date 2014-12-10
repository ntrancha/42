/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 09:31:18 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/10 09:31:18 by ntrancha         ###   ########.fr       */
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

static int   display_link(char *file, char *path, int size, t_param *param)
{
    char    *str;
    char    *tmp;
	int     ret;
    t_stat      s;

    str = ft_strjoin(path, "/");
    tmp = ft_strjoin(str, file);
	ft_strdel(&str);
    str = ft_strnew(size);
    if ((ret = readlink(tmp, str, size)) == -1)
        ft_ls_error(file, param);
    str[ret] = '\0';
    ft_putstr(" -> ");
    ft_putstr(str);
	if (lstat(str, &s) != 0)
        stat(str, &s);
	if (param->carac == 1 && S_ISDIR(s.st_mode))
		ft_putchar('/');
	ft_strdel(&str);
	ft_strdel(&tmp);
}
int             display_list(t_list *file, t_llist *root, t_param *param)
{
    t_stat      s;
    char        *str;
    char        *tmp;

    tmp = ft_strjoin(root->path, "/");
    str = ft_strjoin(tmp, file->str);
    ft_strdel(&tmp);
    if (lstat(str, &s) != 0)
        if (stat(str, &s) != 0)
            return (-1);
    print_rights(s.st_mode, param);
    print_link(root, s);
    print_users(root, s, param);
    print_minor(root, s, file);
    if (param->u == 1)
        print_size_atime(root, s);
    else if (param->c == 1)
        print_size_ctime(root, s);
    else
        print_size_mtime(root, s);
    display_std(file->str, param, root);
    ft_strdel(&str);
    return (0);
}

int             display_std(char *file, t_param *param, t_llist *root)
{
    t_stat      s;
    char        *str;
    char        *tmp;

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
        option_carac(s, param);
	if (S_ISLNK((s).st_mode) && param->l == 1)
		display_link(file, root->path, s.st_size, param);	
    ft_putstr("\n");
    ft_strdel(&str);
    return (0);
}

void            display_file(t_dos **file, t_param *param)
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

