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
#include "recup.h"
#include "list.h"
#include "param.h"
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

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
