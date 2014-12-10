/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_set.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 21:05:58 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/07 21:05:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "param.h"

static int  paramset_option_next(t_param *param, char *str, int c)
{
    if (str[c] == 'u')
        param->u = 1;
    else if (str[c] == 'S')
        param->s = 1;
    else if (str[c] == 'G')
        param->group = 1;
    else if (str[c] == 'R')
        param->recursive = 1;
    else if (str[c] == 'a')
        param->a = 1;
    else if (str[c] == 'r')
        param->r = -1;
    else if (str[c] == 'c')
        param->c = 1;
    else if (str[c] != 'g')
		return (0);
	return (1);
}

static int  paramset_option(t_param *param, char *str, int c)
{
    if (str[c] == 'l' || str[c] == 'n' || str[c] == 'o' || str[c] == 'M')
	{
    	if (str[c] == 'o')
        	param->group = 1;
    	else if (str[c] == 'n')
        	param->n = 1;
    	else if (str[c] == 'M')
        	param->mode = 1;
        param->l = 1;
	}
    else if (str[c] == 't')
        param->t = 1;
    else if (str[c] == 'p')
        param->p = 1;
    else if (str[c] == 'F')
        param->carac = 1;
    else if (str[c] == 'i')
        param->inode = 1;
    else if (str[c] == 'm')
        param->commas = 1;
    else if (str[c] == 'A')
        param->almost = 1;
	else
		return (paramset_option_next(param, str, c));
	return (1);
}

static int  paramset_next(t_param *param, char *str, int count)
{
    if (paramset_option(param, str, count) == 0)
    {
        ft_putstr("option invalide -- '");
        ft_putchar(str[count]);
        ft_putstr("'\n");
        return (-1);
    }
    count++;
    return (count);
}

char        ft_ls_paramset(t_param *param, char *str)
{
    int     count;

    count = 1;
    if (param == NULL || str == NULL)
        return (0);
    while (str[count])
    {
        count = paramset_next(param, str, count);
        if (count == -1)
            return (-1);
    }
    return (0);
}
