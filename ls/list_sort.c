/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:37:20 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/29 10:26:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "list.h"

int			ft_list_permutte(t_llist *repere, t_list *node)
{
    t_list  *prev2;
    t_list  *next3;
    t_list  *tmp3;

    if (repere && node && node->next)
    {
        tmp3 = node->next;
        prev2 = node->previous;
        next3 = tmp3->next;
        if (node->previous)
            node->previous->next = tmp3;
        else
            repere->start = tmp3;
        if (tmp3->next)
            tmp3->next->previous = node;
        else
            repere->end = node;
        node->previous = tmp3;
        tmp3->next = node;
        tmp3->previous = prev2;
        node->next = next3;
		return (1);
    }
	return (0);
}

int        ft_list_sort_name2(t_llist *list, int s, int test2)
{
    char    *str1;
    char    *str2;
    t_list  *node;
	int		test;

    node = list->start;
    while (node && node->next)
    {
        str1 = node->str;
        str2 = node->next->str;
		test = 0;
        if (ft_strcmp(str1, str2) < 0 && s < 0)
			test = 1;
        if ((ft_strcmp(str1, str2) > 0 && s > 0) || test == 1)
		{
			if (str1 && str2)
				test2 = ft_list_permutte(list, node);
		}
        else
            node = node->next;
    }
	return (test2);
}

int        ft_list_sort_name(t_llist *list, int s)
{
	if (list == NULL)
		return (-1);
	if (ft_list_sort_name2(list, s, 0) == 1)
       	return (ft_list_sort_name(list, s));
	return (s);
}

int        ft_list_sort_size(t_llist *list, int s)
{
	int		test;
	int		test2;
    int     size1;
    int     size2;
    t_list  *node;

        node = list->start;
		test2 = 0;
        while (node && node->next)
        {
            size1 = node->time->size;
            size2 = node->next->time->size;
			test = 0;
            if (size1 > size2 && s > 0)
				test = 1;
            if ((size1 < size2 && s < 0) || test == 1)
                test2 = ft_list_permutte(list, node);
            else
                node = node->next;
        }
		if (test2 == 1)
           	return (ft_list_sort_size(list, s));
		return (s);
}
