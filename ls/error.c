/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 15:16:55 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/06 15:16:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "param.h"
#include <libft.h>
#include <errno.h>

void        ft_ls_error(char *str, t_param *param)
{
    ft_putstr(param->prog_name);
    ft_putstr(": ");
    ft_putstr(str);
    ft_putstr(": ");
    ft_putstr(strerror( errno ));
    ft_putstr("\n");
}
