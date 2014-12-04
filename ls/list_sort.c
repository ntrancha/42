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

#include "list.h"
#include <stdlib.h>

void		ft_list_permutte(t_llist *repere, t_list *node)
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
    }
}

int        ft_list_sort_name(t_llist *list, int s)
{
	int		test;
    char    *str1;
    char    *str2;
    t_list  *node;

	if (list == NULL)
		return (-1);
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
	            	ft_list_permutte(list, node);
           		return (ft_list_sort_name(list, s));
			}
            else
                node = node->next;
        }
		return (s);
}

int        ft_list_sort_size(t_llist *list, int s)
{
	int		test;
    int     size1;
    int     size2;
    t_list  *node;

        node = list->start;
        while (node && node->next)
        {
            size1 = node->time->size;
            size2 = node->next->time->size;
			test = 0;
            if (size1 > size2 && s > 0)
				test = 1;
            if ((size1 < size2 && s < 0) || test == 1)
			{
                ft_list_permutte(list, node);
           		return (ft_list_sort_size(list, s));
			}
            else
                node = node->next;
        }
		return (s);
}

int        ft_list_sort_mtime(t_llist *list, int s)
{
	int		test;
    long    size1;
    long    size2;
    t_list  *node;

    node = list->start;
    while (node && node->next)
    {
        size1 = node->time->mtime;
        size2 = node->next->time->mtime;
		test = 0;
        if (size1 > size2 && s < 0)
			test = 1;
        if ((size1 < size2 && s > 0) || test == 1)
		{
			ft_list_permutte(list, node);
           	return (ft_list_sort_mtime(list, s));
		}
        else
            node = node->next;
	}
	return (s);
}

int			ft_list_sort_path(t_llist **racine, int sort)
{
	t_llist	*prev;
	t_llist	*tmp;
	t_llist	*next;

	prev = NULL;
	tmp = (*racine);
	next = (*racine)->next;
	while (next)
	{
		if ((ft_strcmp(tmp->path, next->path) > 0 && sort > 0) ||
				(ft_strcmp(tmp->path, next->path) < 0 && sort < 0))
		{
			if (prev)
				prev->next = next;
			else
				(*racine) = next;
			tmp->next = next->next;
			next->next = tmp;
			return (ft_list_sort_path(racine, sort));
		}
		prev = tmp;
		tmp = tmp->next;
		next = tmp->next;
	}
	return (1);
}


/*
int        ft_list_sort_ctime(t_llist *list, int s)
{
	int		test;
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


int        ft_list_sort_atime(t_llist *list, int s)
{
	int		test;
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
}*/
