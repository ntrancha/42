/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dos.c												:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:38:25 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/26 14:38:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dos.h"
#include <stdlib.h>

t_dos		*ft_list_dos_create(char *path)
{
    char	*str;
	t_dos	*racine;

		racine = malloc(sizeof(t_dos));
		if (racine == NULL || path == NULL || ft_strlen(path) == 0)
			return (NULL);
    	str = malloc(sizeof(char) * ft_strlen(path) + 1);
		if (!str)
		{
			ft_memdel(&racine);
			return (NULL);
		}
		racine->next = NULL;
        ft_strcpy(str, path);
		racine->str = str;
		return (racine);
}

t_dos		*ft_list_dos_new(char *path, t_dos *racine)
{
    t_dos	*p_new;
    t_dos	*tmp;
    char	*str;

	if (!racine)
		return (ft_list_dos_create(path));
    p_new = malloc(sizeof(t_dos));
	if (p_new == NULL)
		return (NULL);
    str = malloc(sizeof(char) * ft_strlen(path) + 1);
	if (str == NULL)
	{
		ft_memdel(&p_new);
		return (NULL);
	}
	tmp = racine;
    ft_strcpy(str, path);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = p_new;
    p_new->next = NULL;
    p_new->str = str;
	return (racine);
}

void		ft_list_dos_del(t_dos **racine)
{
    t_dos	*tmp;
    t_dos	*tmp2;

	tmp = (*racine);
	tmp2 = NULL;
	if (tmp)
	{
		tmp2 = tmp->next;
		ft_strdel(&tmp->str);
		ft_memdel(&tmp);
		tmp = NULL;
		(*racine) = tmp2;
	}
}

t_dos	*ft_list_dos_free(t_dos **racine)
{
	while ((*racine))
		ft_list_dos_del(racine);
	return (NULL);
}

int			ft_list_dos_sort(t_dos **racine, int sort)
{
    t_dos	*prev;
	t_dos	*tmp;
	t_dos	*next;

	prev = NULL;
	tmp = (*racine);
	next = (*racine)->next;
	while (next)
	{
		if ((ft_strcmp(tmp->str, next->str) > 0 && sort > 0) ||
				(ft_strcmp(tmp->str, next->str) < 0 && sort < 0))
		{
			if (prev)
				prev->next = next;
			else
				(*racine) = next;
			tmp->next = next->next;
			next->next = tmp;
			return (ft_list_dos_sort(racine, sort));
		}
		prev = tmp;
		tmp = tmp->next;
		next = tmp->next;
	}	
	return (1);
}
