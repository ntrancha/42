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

#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

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
	((m & S_IRUSR) != 0) ? ft_putchar('r') : ft_putchar('-');
	((m & S_IWUSR) != 0) ? ft_putchar('w') : ft_putchar('-');
	((m & S_IXUSR) != 0) ? ft_putchar('x') : ft_putchar('-');
	((m & S_IRGRP) != 0) ? ft_putchar('r') : ft_putchar('-');
	((m & S_IWGRP) != 0) ? ft_putchar('w') : ft_putchar('-');
	((m & S_IXGRP) != 0) ? ft_putchar('x') : ft_putchar('-');
	((m & S_IROTH) != 0) ? ft_putchar('r') : ft_putchar('-');
	((m & S_IWOTH) != 0) ? ft_putchar('w') : ft_putchar('-');
	((m & S_IXOTH) != 0) ? ft_putchar('x') : ft_putchar('-');
}
