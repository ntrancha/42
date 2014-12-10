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

#include <stdlib.h>
#include <libft.h>
#include "param.h"

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
	param->u = 0;
	param->s = 0;
	param->c = 0;
	param->m = -1;
	param->f = 0;
	param->p = 0;
	param->carac = 0;
	param->almost = 0;
	param->inode = 0;
	param->commas = 0;
	param->total = 0;
	param->list_total = 0;
	param->recursive = 0;
	param->prog_name = NULL;
	return (param);
}

t_param		*ft_ls_param_del(t_param *param)
{
	ft_strdel(&param->prog_name);
	ft_memdel((void*)&param);
	return (NULL);
}
