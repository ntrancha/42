/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_max_nbr.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 20:00:33 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/07 20:00:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "param.h"
#include "list.h"
#include "recup.h"
#include "date.h"
#include "extra.h"
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int     ft_nbrlen(int nbr)
{
    int ret;

    ret = 0;
    if (nbr < 0)
    {
        nbr *= -1;
        ret = 1;
    }
    while (nbr > 0)
    {
        nbr /= 10;
        ret++;
    }
    return (ret);
}

int     date_max_len(t_llist *root, int ret, t_param *param)
{
    int temp;
    t_list  *list;
    t_stat  s;
    char        *str;
    char        *tmp;

    tmp = 0;
    list = root->start;
    while (list != NULL)
    {
        tmp = ft_strjoin(root->path, "/");
        str = ft_strjoin(tmp, list->str);
        if (lstat(str, &s) == 0  && file_get(list, param) == 1)
        {
            temp = ft_strlen(date_mois(ctime(&s.st_mtime)));
            if (temp > ret)
                ret = temp;
        }
        list = list->next;
        ft_strdel(&str);
        ft_strdel(&tmp);
    }
    return (ret);
}

int     size_max_len(t_llist *root, int ret, t_param *param)
{
    int temp;
    t_list  *list;
    t_stat  s;
    char        *str;
    char        *tmp;

    tmp = 0;
    list = root->start;
    while (list != NULL)
    {
        tmp = ft_strjoin(root->path, "/");
        str = ft_strjoin(tmp, list->str);
        if (lstat(str, &s) == 0  && file_get(list, param) == 1)
        {
            temp = ft_nbrlen(s.st_size);
            if (temp > ret)
                ret = temp;
        }
        list = list->next;
        ft_strdel(&str);
        ft_strdel(&tmp);
    }
    return (ret);
}

int     links_max_len(t_llist *root, int ret, t_param *param)
{
    int temp;
    t_list  *list;
    t_stat  s;
    char        *str;
    char        *tmp;

    tmp = 0;
    list = root->start;
    while (list != NULL)
    {
        tmp = ft_strjoin(root->path, "/");
        str = ft_strjoin(tmp, list->str);
        if (lstat(str, &s) == 0  && file_get(list, param) == 1)
        {
            temp = ft_nbrlen(s.st_nlink);
            if (temp > ret)
                ret = temp;
        }
        list = list->next;
        ft_strdel(&str);
        ft_strdel(&tmp);
    }
    return (ret);
}
