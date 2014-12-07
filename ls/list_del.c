/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c													:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:31:04 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/26 18:31:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "list.h"
#include "list_del.h"

t_llist     *ft_list_del_node(t_llist *repere, t_list *node)
{
    if (repere != NULL && node != NULL)
    {
        if (node->stats)
        {
            ft_memdel((void*)&(node->stats->user));
            ft_memdel((void*)&(node->stats->group));
            ft_memdel((void*)&(node->stats));
        }
        ft_memdel((void*)&(node->time));
        ft_memdel((void*)&(node->str));
        if (repere->end == node)
            repere->end = node->previous;
        if (repere->start == node)
            repere->end = node->next;
        ft_memdel((void*)&node);
        repere->length--;
        return (repere);
    }
    return (NULL);
}

t_llist     *ft_list_del_path(t_llist *repere)
{
    t_llist *ret;

    if (repere == NULL)
        return (NULL);
    ret = repere->next;
    while (repere->length > 0)
    {
        repere = ft_list_del_node(repere, repere->end);
        if (repere == NULL)
            return (NULL);
    }
    ft_memdel((void*)&repere->path);
    ft_memdel((void*)&repere);
    return (ret);
}

t_llist     *ft_list_del(t_llist *repere)
{
    t_llist *ret;

    if (repere == NULL)
        return (NULL);
    ret = repere;
    while (ret != NULL)
    {
        ret = repere->next;
        repere = ft_list_del_path(repere);
        if (repere == NULL || ret == NULL)
            return (NULL);
    }
    return (NULL);
}
