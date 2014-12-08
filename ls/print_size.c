/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:55:58 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/08 09:55:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "param.h"
#include "list.h"
#include "recup.h"
#include "print.h"
#include "date.h"
#include "extra.h"
#include "option.h"
#include "size_max_nbr.h"
#include "size_max_str.h"
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void   print_size_atime(t_llist *root, t_stat s)
{
    char    *tmp;

    ft_putstr(date_mois(ctime(&s.st_atime)));
    print_space(root->size_date - ft_strlen(date_mois(ctime(&s.st_atime))) + 1);
    ft_putstr(date_date(ctime(&s.st_atime)));
    ft_putstr(" ");
    if (s.st_atime > time(NULL) + (24 * 60 * 60 * 365 / 2) + 60)
        tmp = date_hour(ctime(&s.st_atime));
    else
        tmp = date_year(ctime(&s.st_atime));
    print_space(root->size_date - ft_strlen(tmp) + 2);
    ft_putstr(tmp);
    ft_putstr(" ");
    ft_strdel(&tmp);
}

void   print_size_ctime(t_llist *root, t_stat s)
{
    char    *tmp;

    ft_putstr(date_mois(ctime(&s.st_ctime)));
    print_space(root->size_date - ft_strlen(date_mois(ctime(&s.st_ctime))) + 1);
    ft_putstr(date_date(ctime(&s.st_ctime)));
    ft_putstr(" ");
    if (s.st_ctime > time(NULL) + (60 * 60 * 24 * 365 / 2) + 60)
        tmp = date_hour(ctime(&s.st_ctime));
    else
        tmp = date_year(ctime(&s.st_ctime));
    print_space(root->size_date - ft_strlen(tmp) + 2);
    ft_putstr(tmp);
    ft_putstr(" ");
    ft_strdel(&tmp);
}

void   print_size_mtime(t_llist *root, t_stat s)
{
    char    *tmp;

    ft_putstr(date_mois(ctime(&s.st_mtime)));
    print_space(root->size_date - ft_strlen(date_mois(ctime(&s.st_mtime))) + 1);
    ft_putstr(date_date(ctime(&s.st_mtime)));
    ft_putstr(" ");
    if (s.st_mtime > time(NULL) + (60 * 60 * 24 * 365 / 2) + 60)
        tmp = date_hour(ctime(&s.st_mtime));
    else
        tmp = date_year(ctime(&s.st_mtime));
    print_space(root->size_date - ft_strlen(tmp) + 2);
    ft_putstr(tmp);
    ft_putstr(" ");
    ft_strdel(&tmp);
}
