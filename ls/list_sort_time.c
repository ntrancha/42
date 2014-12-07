/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_time.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 22:29:36 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/07 22:29:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "list.h"
#include "list_sort.h"

int        ft_list_sort_atime(t_llist *list, int s)
{
    int     test;
    long    size1;
    long    size2;
    t_list  *node;

    node = list->start;
    while (node && node->next)
    {
        size1 = node->time->atime;
        size2 = node->next->time->atime;
        test = 0;
        if (size1 > size2 && s > 0)
            test = 1;
        if ((size1 < size2 && s < 0) || test == 1)
        {
            ft_list_permutte(list, node);
            return (ft_list_sort_atime(list, s));
        }
        else
            node = node->next;
    }
    return (s);
}

int        ft_list_sort_ctime(t_llist *list, int s)
{
    int     test;
    long    size1;
    long    size2;
    t_list  *node;

    node = list->start;
    while (node && node->next)
    {
        size1 = node->time->ctime;
        size2 = node->next->time->ctime;
        test = 0;
        if (size1 > size2 && s > 0)
            test = 1;
        if ((size1 < size2 && s < 0) || test == 1)
        {
            ft_list_permutte(list, node);
            return (ft_list_sort_ctime(list, s));
        }
        else
            node = node->next;
    }
    return (s);
}

int        ft_list_sort_mtime(t_llist *list, int s)
{
    int     test;
    int     test2;
    long    size1;
    long    size2;
    t_list  *node;

    if (list == NULL)
        return (-1);
    node = list->start;
    test2 = 0;
    while (node && node->next)
    {
        size1 = node->time->mtime;
        size2 = node->next->time->mtime;
        test = 0;
        if (size1 > size2 && s < 0)
            test = 1;
        if ((size1 < size2 && s > 0) || test == 1)
            test2 = ft_list_permutte(list, node);
        else
            node = node->next;
    }
    if (test2 == 1)
        return (ft_list_sort_mtime(list, s));
    return (s);
}
