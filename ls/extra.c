/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:54:46 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/02 13:54:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "recup.h"
#include "list.h"
#include "list_del.h"
#include "param.h"
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

t_llist		*recursive_path(t_llist *root, t_param *param, char *str)
{
	t_llist *dir;
	t_llist *prev;
	t_llist *tmp;

	dir = root;
	prev = NULL;
	tmp = NULL;
	while (dir && dir->path && !ft_ls_test_dir(dir->path))
	{
			ft_ls_error(dir->path, param);
			while (dir->length > 0)
		    {
		        dir = ft_list_del_node(dir, dir->end);
		        if (dir == NULL)
		            return (NULL);
		    }
			ft_strdel(&(dir->path));
			if (prev != NULL)
				prev->next = dir->next;
			tmp = dir->next;
			ft_memdel((void*)&dir);
			dir = tmp;
	}
	return (dir);
}

char    *get_group(t_stat s)
{
    t_group      *group;

    group = getgrgid(s.st_gid);
    if (group == NULL)
        return (NULL);
    return (group->gr_name);
}

int     file_ok(t_list *list, t_param *param)
{
    if (param->a == 1)
        return (1);
    else
        if (ft_strcmp(list->str, "..") != 0)
            if (ft_strcmp(list->str, ".") != 0)
            	if (list->str[0] != '.' || param->almost == 1)
               		return (1);
    return (0);
}

char    *get_user(t_stat s)
{
    t_pass      *pass;

    pass = getpwuid(s.st_uid);
    return (pass->pw_name);
}

void	print_mode(mode_t m)
{
	int	mod;

	mod = 0;
    if ((m & S_IRUSR) != 0)
		mod += 400;
    if ((m & S_IWUSR) != 0)
		mod += 200;
    if ((m & S_IXUSR) != 0)
		mod += 100;
    if ((m & S_IRGRP) != 0)
		mod += 40;
    if ((m & S_IWGRP) != 0)
		mod += 20;
    if ((m & S_IXGRP) != 0)
		mod += 10;
    if ((m & S_IROTH) != 0)
		mod += 4;
    if ((m & S_IWOTH) != 0)
		mod += 2;
    if ((m & S_IXOTH) != 0)
		mod += 1;
	ft_putnbr(mod);
}
