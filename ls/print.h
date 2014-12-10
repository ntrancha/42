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

void	print_rights(mode_t m, t_param *param);
void   print_link(t_llist *root, t_stat s);
void   print_users(t_llist *root, t_stat s, t_param *param);
void   print_minor(t_llist *root, t_stat s, t_list *fichier);
void    print_space(int nbr);

#endif
