/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 20:35:03 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 10:18:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "param.h"
#include <stdlib.h>

int			ft_ls_paramset_next(t_param *param, char *str, int count)
{
	if (str[count] == 'l')
		param->l = 1;
	else if (str[count] == 'R')
		param->recursive = 1;
	else if (str[count] == 'a')
		param->a = 1;
	else if (str[count] == 'r')
		param->r = -1;
	else if (str[count] == 't')
		param->t = 1;
	else
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
		count = ft_ls_paramset_next(param, str, count);
		if (count == -1)
			return (-1);
	}
	return (0);
}

int         ft_ls_param(char *str)
{
	if (str[0] && str[1])
		if (str[0] == '-' && str[1] == '-')
			return (-1);
	if (str[0])
		if (str[0] == '-')
			return (1);
	return (0);
}

t_param		*ft_ls_param_new(void)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (param == NULL)
		return (NULL);
	param->l = 0;
	param->r = 1;
	param->a = 0;
	param->t = 0;
	param->m = -1;
	param->f = 0;
	param->recursive = 0;
	param->prog_name = NULL;
	return (param);
}

t_param		*ft_ls_param_del(t_param *param)
{
	ft_strdel(&param->prog_name);
	ft_memdel(&param);
	return (NULL);
}
