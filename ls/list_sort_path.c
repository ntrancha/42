/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_path.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 20:47:59 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/05 20:47:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "list.h"

int         path(t_llist **root, t_llist **tmp, t_llist **prev, t_llist **next)
{
    if (*prev)
        (*prev)->next = *next;
    else
        (*root) = *next;
    (*tmp)->next = (*next)->next;
    (*next)->next = *tmp;
    return (1);
}

int         ft_list_sort_path2(t_llist **racine, int sort, int test)
{
    t_llist *prev;
    t_llist *tmp;
    t_llist *next;

    prev = NULL;
    tmp = (*racine);
    next = (*racine)->next;
    while (next)
    {
        if ((ft_strcmp(tmp->path, next->path) > 0 && sort > 0) ||
                (ft_strcmp(tmp->path, next->path) < 0 && sort < 0))
            test = path(racine, &tmp, &prev, &next);
        prev = tmp;
        tmp = tmp->next;
        if (tmp != NULL && tmp->next != NULL)
            next = tmp->next;
        else
            next = NULL;
    }
    return (test);
}

int         ft_list_sort_path(t_llist **racine, int sort)
{
    if (racine == NULL)
        return (-1);
    if (ft_list_sort_path2(racine, sort, 0) == 1)
        return (ft_list_sort_path(racine, sort));
    return (1);
}
