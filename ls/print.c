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

void   print_minor(t_llist *root, t_stat s)
{
	int	len;

    if (S_ISCHR(s.st_mode) || S_ISBLK(s.st_mode))
	{
    	print_space(root->size_minor - ft_nbrlen(minor(s.st_rdev)));
		ft_putnbr(minor(s.st_rdev));
		ft_putstr(", ");
    	print_space(root->size_major - ft_nbrlen(major(s.st_rdev)));
		ft_putnbr(major(s.st_rdev));
		ft_putstr(" ");
	}
	else
	{
		if (root->size_major > 0)
			len = root->size_major + root->size_minor - 3;
		else
			len = root->size_major + root->size_minor - 1;
		print_space(len + root->size_size - ft_nbrlen(s.st_size) + 1);
    	ft_putnbr(s.st_size);
    	ft_putstr(" ");
	}
}

void   print_users(t_llist *root, t_stat s, t_param *param)
{
	int			len;

	if (param->n == 1)
	{
    	len = ft_nbrlen(s.st_uid);
    	print_space(root->size_user - len);
		ft_putnbr(s.st_uid);
	}
	else
	{
	    ft_putstr(get_user(s));
    	len = ft_strlen(get_user(s));
    	print_space(root->size_user - len + 1 - param->group);
	}
	if (param->group == 0 && param->n == 0)
    {
        ft_putstr(get_group(s));
        len = ft_strlen(get_group(s));
        print_space(root->size_group - len);
    }
	if (param->n == 1 && param->group == 0)
	{
        len = ft_nbrlen(s.st_gid);
        print_space(root->size_group - len + 1);
		ft_putnbr(s.st_gid);
	}
	ft_putchar(' ');
}

void   print_link(t_llist *root, t_stat s)
{
	print_space(root->size_link - ft_nbrlen(s.st_nlink) + 1);
    ft_putnbr(s.st_nlink);
    ft_putstr(" ");
}

void	print_rights(mode_t m, t_param *param)
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
	if (param->mode == 0)
		option_list(m);
	else
		print_mode(m);
}
