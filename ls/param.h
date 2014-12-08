/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:58:10 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 11:06:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_H
# define PARAM_H

typedef struct	s_param	t_param;

struct          s_param
{   
    int         l;
    int         recursive;
    int         a;
    int         r; 
    int         t; 
    int         m; 
    int         s; 
    int         u; 
    int         c; 
    int         f; 
    int         p; 
    int         carac; 
    int         commas; 
    int         total; 
    int         almost; 
    int         inode; 
    char		*prog_name; 
};

int		ft_ls_param(char *str);
t_param	*ft_ls_param_new(void);
t_param	*ft_ls_param_del(t_param *param);

#endif
