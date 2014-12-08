/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:14:24 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/27 11:25:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "list.h"

t_llist         *ft_list_create(char *path)
{   
    char        *str;
    t_llist     *p_new;
    
    p_new = malloc(sizeof(t_llist));
	if (p_new == NULL)
		return (NULL);
    str = malloc(sizeof(char) * ft_strlen(path) + 1);
	if (str == NULL)
	{
		ft_memdel((void*)&p_new);
		return (NULL);
	}
    ft_strcpy(str, path);
    p_new->length = 0;
    p_new->start = NULL;
    p_new->end = NULL;
    p_new->next = NULL;
    p_new->path = str;
    return (p_new);
}

t_list			*ft_list_add_malloc(void)
{
    t_list      *item;
    t_stats     *stats;
    t_time      *time;

    item = malloc(sizeof(t_list));
	if (item == NULL)
		return (NULL);
    stats = malloc(sizeof(t_stats));
	if (stats == NULL)
	{
		ft_memdel((void*)&item);
		return (NULL);
	}
    time = malloc(sizeof(t_time));
	if (time == NULL)
	{
		ft_memdel((void*)&item);
		ft_memdel((void*)&stats);
		return (NULL);
	}
    item->stats = stats;
    item->time = time;
	return (item);
}

t_llist         *ft_list_add_complete(t_llist *repere, int size)
{
    repere->length++;
	repere->end->stats->hidden = 0;
	repere->end->stats->mode = 0;
	repere->end->stats->user = NULL;
	repere->end->stats->group = NULL;
	repere->end->stats->type = '\0';
	repere->end->time->size = size;
	repere->end->time->atime = 0;
	repere->end->time->ctime = 0;
	repere->end->time->mtime = 0;
	repere->size_link = 0;
	repere->size_user = 0;
	repere->size_group = 0;
	repere->size_minor = 0;
	repere->size_major = 0;
	repere->size_size = 0;
	repere->size_date = 0;
	repere->size_year = 0;
	return (repere);
}

t_llist         *ft_list_add(t_llist *repere, char *valeur, int size)
{
    t_list      *new_item;
    char        *str;

    if (!repere)
        repere = ft_list_create(".");
    str = malloc(sizeof(char) * ft_strlen(valeur) + 1);
	if (str == NULL)
		return (NULL);
    new_item = ft_list_add_malloc();
	if (new_item == NULL)
	{
		ft_memdel((void*)&str);
		return (NULL);
	}
    ft_strcpy(str, valeur);
    new_item->str = str;
    new_item->next = NULL;
    new_item->previous = repere->end;
    if (repere->end == NULL)
        repere->start = new_item;
    else
        repere->end->next = new_item;
    repere->end = new_item;
	return (ft_list_add_complete(repere, size));
}

t_llist			*ft_list_add_dir(t_llist *racine, char *path)
{
    t_llist     *p_new;
    t_llist     *repere;

	if (racine == NULL)
		return (NULL);
    p_new = ft_list_add(NULL, path , 0);
	if (p_new == NULL)
		return (NULL);
	repere = racine;
    while (repere->next != NULL)
        repere = repere->next;
    repere->next = p_new;
	ft_memdel((void*)&repere->next->path);
	repere->next->path = malloc(sizeof(char) * ft_strlen(path) + 1);
	ft_strcpy(repere->next->path, path);
	return (racine);
}
