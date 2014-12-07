/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_max_str.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 20:05:27 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/07 20:05:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "param.h"
#include "list.h"
#include "recup.h"
#include "date.h"
#include "extra.h"
#include "size_max_nbr.h"
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int     group_max_len(t_llist *root, int ret, int temp, t_param *param)
{
    char    *tmp;
    t_list  *list;
    t_stat  s;
    char    *str;

    list = root->start;
    while (list != NULL)
    {
        tmp = ft_strjoin(root->path, "/");
        str = ft_strjoin(tmp, list->str);
        if (lstat(str, &s) == 0 && file_get(list, param) == 1)
        {
            temp = ft_strlen(get_group(s));
            if (temp > ret)
                ret = temp;
        }
        list = list->next;
        ft_strdel(&str);
        ft_strdel(&tmp);
    }
    return (ret);
}

int     user_max_len(t_llist *root, int ret, int temp, t_param *param)
{
    char    *tmp;
    t_list  *list;
    t_stat  s;
    char    *str;

    list = root->start;
    while (list != NULL)
    {
        tmp = ft_strjoin(root->path, "/");
        str = ft_strjoin(tmp, list->str);
        if (lstat(str, &s) == 0  && file_get(list, param) == 1)
        {
            temp = ft_strlen(get_user(s));
            if (temp > ret)
                ret = temp;
        }
        list = list->next;
        ft_strdel(&str);
        ft_strdel(&tmp);
    }
    return (ret);
}

int     year_max_len(t_llist *root, int ret, t_param *param)
{
    int temp;
    t_list  *list;
    t_stat  s;
    char        *str;
    char        *tmp;

    temp = 0;
    list = root->start;
    while (list != NULL)
    {
        tmp = ft_strjoin(root->path, "/");
        str = ft_strjoin(tmp, list->str);
        if (lstat(str, &s) == 0  && file_get(list, param) == 1)
        {
            if (s.st_mtime > time(NULL) + 60 - 60 * 60 * 24 * 365)
                temp = 5;
            else
                temp = 4;
            if (temp > ret)
                ret = temp;
        }
        list = list->next;
        ft_strdel(&str);
        ft_strdel(&tmp);
    }
    return (ret);
}

int     strs_max_len(t_llist *root, t_param *param)
{
    int ret;
    int tmp;
    t_list  *list;

    ret = 0;
    tmp = 0;
    list = root->start;
    while (list != NULL)
    {
        tmp = ft_strlen(list->str);
        if (tmp > ret && file_get(list, param) == 1)
            ret = tmp;
        list = list->next;
    }
    return (ret);
}