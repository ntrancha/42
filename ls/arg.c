/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 09:52:06 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/10 09:52:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "param.h"
#include "param_set.h"
#include "list.h"
#include "dos.h"

static int      arg_option(t_param *param, int argc, char **argv)
{
    int         count;

    count = 0;
    while (++count < argc && argv[count][0] == '-')
    {
        if (ft_ls_param(argv[count]) == 1)
            if (ft_ls_paramset(param, argv[count]))
                return (-1);
    }
    count--;
    param->prog_name = malloc(sizeof(char) * (ft_strlen(argv[0]) + 1));
    ft_strcpy(param->prog_name, argv[0]);
    return (count);
}

t_dos    *arg(t_param *param, int argc, char **argv)
{
    int         count;
    t_dos       *dos;

    dos = NULL;
    param->m++;
    count = arg_option(param, argc, argv);
    if (count == -1)
    {
        param->m = -1;
        return (NULL);
    }
    while (++count < argc)
    {
        param->m++;
            dos = ft_list_dos_new(argv[count], dos);
            if (dos == NULL)
            {
                param->m = -1;
                return (NULL);
            }
    }
    return (dos);
}

