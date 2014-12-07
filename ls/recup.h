/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 08:11:44 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/27 08:27:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECUP_H
# define RECUP_H
# include "param.h"
# include "list.h"
# include "dos.h"

typedef struct	dirent	t_dir;
typedef struct	stat	t_stat;
typedef struct	passwd	t_pass;

int		ft_ls_recup(t_llist *list, t_param *param);
void	ft_ls_recup_file(t_llist *list, t_param *param, t_dir *file);
t_llist	*ft_ls_recup_stats(t_llist *list, t_dir *file);
t_llist	*ft_ls_recup2(t_llist *list, t_stat s, t_dir *file);
void	ft_ls_recup_mode(t_llist *list, t_dir *file);


#endif
