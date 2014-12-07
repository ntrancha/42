/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:15:39 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 11:20:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include <sys/stat.h>
# include "param.h"
# include "list.h"
# include "recup.h"

void	print_rights(mode_t m);
int     strs_max_len(t_llist *root);
void    print_space(int nbr);
char    *get_user(t_stat s);
int     ft_nbrlen(int nbr);
char    *get_group(t_stat s);
int     file_get(t_list *list, t_param *param);
int     group_max_len(t_llist *root, int ret, int temp, t_param *param);
int     user_max_len(t_llist *root, int ret, int temp, t_param *param);
int     size_max_len(t_llist *root, int ret, t_param *param);
int     links_max_len(t_llist *root, int ret, t_param *param);


#endif
