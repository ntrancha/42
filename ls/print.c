/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:14:53 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 11:20:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "param.h"
#include "list.h"
#include "recup.h"
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

void	print_space(int nbr)
{
	while (nbr-- > 0)
		ft_putchar(' ');
}

void   print_size_time(t_llist *root, t_stat s)
{
	char	*tmp;

	print_space(root->size_size - ft_nbrlen(s.st_size));
    ft_putnbr(s.st_size);
    ft_putstr(" ");
    ft_putstr(date_mois(ctime(&s.st_mtime)));
    print_space(root->size_date - ft_strlen(date_mois(ctime(&s.st_mtime))) + 1);
    ft_putstr(date_date(ctime(&s.st_mtime)));
    ft_putstr(" ");
    if (s.st_mtime > time(NULL) + 60 - 60 * 60 * 24 * 365)
        tmp = date_hour(ctime(&s.st_mtime));
    else
        tmp = date_year(ctime(&s.st_mtime));
    print_space(root->size_date - ft_strlen(tmp) + 2);
    ft_putstr(tmp);
    ft_putstr(" ");
	ft_strdel(&tmp);
}

void   print_users(t_llist *root, t_stat s)
{
	t_pass      *pass;
	int			len;

	pass = getpwuid(s.st_uid);
    ft_putstr(pass->pw_name);
    len = ft_strlen(pass->pw_name);
    print_space(root->size_user - len + 1);
    pass = getpwuid(s.st_gid);
	if (pass != NULL)
    {
        ft_putstr(pass->pw_name);
        len = ft_strlen(pass->pw_name);
        print_space(root->size_group - len + 1);
    }
}

void   print_link(t_llist *root, t_stat s)
{
	print_space(root->size_link - ft_nbrlen(s.st_nlink) + 1);
    ft_putnbr(s.st_nlink);
    ft_putstr(" ");
}

void	print_rights(mode_t m)
{
	if (S_ISREG(m))
		ft_putchar('-');
	else if (S_ISDIR(m))
		ft_putchar('d');
	else if (S_ISLNK(m))
		ft_putchar('l');
	else if (S_ISFIFO(m))
		ft_putchar('p');
	else if (S_ISBLK(m))
		ft_putchar('b');
	else if (S_ISCHR(m))
		ft_putchar('c');
	else if (S_ISSOCK(m))
		ft_putchar('s');
	option_list(m);
}
