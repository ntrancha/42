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
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/ioctl.h>

int		ft_nbrlen(int nbr)
{
	int	ret;

	ret = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		ret = 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}

char	*get_group(t_stat s)
{
	t_pass      *pass;

	pass = getpwuid(s.st_gid);
	if (pass == NULL)
		return (NULL);
    return (pass->pw_name);
}

int		file_get(t_list *list, t_param *param)
{
	if (param->a == 1)
		return (1);
	else
		if (ft_strcmp(list->str, "..") != 0)
			if (ft_strcmp(list->str, ".") != 0)
				return (1);
	return (0);
}

int		group_max_len(t_llist *root, int ret, int temp, t_param *param)
{
	char	*tmp;
	t_list	*list;
	t_stat	s;
	char    *str;

	list = root->start;
	while (list != NULL)
	{
	    tmp = ft_strjoin(root->path, "/");
		str = ft_strjoin(tmp, list->str);
	    if (lstat(str, &s) == 0 && file_get(list, param) == 1)
		{
			temp = ft_strlen(get_group(s));
			if (temp > ret)
				ret = temp;
		}
		list = list->next;
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
	return (ret);
}

char	*get_user(t_stat s)
{
	t_pass      *pass;

	pass = getpwuid(s.st_uid);
    return (pass->pw_name);
}

int		user_max_len(t_llist *root, int ret, int temp, t_param *param)
{
	char	*tmp;
	t_list	*list;
	t_stat	s;
	char    *str;

	list = root->start;
	while (list != NULL)
	{
	    tmp = ft_strjoin(root->path, "/");
		str = ft_strjoin(tmp, list->str);
	    if (lstat(str, &s) == 0  && file_get(list, param) == 1)
		{
			temp = ft_strlen(get_user(s));
			if (temp > ret)
				ret = temp;
		}
		list = list->next;
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
	return (ret);
}

int		size_max_len(t_llist *root, int ret, t_param *param)
{
	int	temp;
	t_list	*list;
	t_stat	s;
	char        *str;
    char        *tmp;

	tmp = 0;
	list = root->start;
	while (list != NULL)
	{
	    tmp = ft_strjoin(root->path, "/");
		str = ft_strjoin(tmp, list->str);
	    if (lstat(str, &s) == 0  && file_get(list, param) == 1)
		{
			temp = ft_nbrlen(s.st_size);
			if (temp > ret)
				ret = temp;
		}
		list = list->next;
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
	return (ret);
}

int		links_max_len(t_llist *root, int ret, t_param *param)
{
	int	temp;
	t_list	*list;
	t_stat	s;
	char        *str;
    char        *tmp;

	tmp = 0;
	list = root->start;
	while (list != NULL)
	{
	    tmp = ft_strjoin(root->path, "/");
		str = ft_strjoin(tmp, list->str);
	    if (lstat(str, &s) == 0  && file_get(list, param) == 1)
		{
			temp = ft_nbrlen(s.st_nlink);
			if (temp > ret)
				ret = temp;
		}
		list = list->next;
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
	return (ret);
}

int		strs_max_len(t_llist *root, t_param *param)
{
	int	ret;
	int	tmp;
	t_list	*list;

	ret = 0;
	tmp = 0;
	list = root->start;
	while (list != NULL)
	{
		tmp = ft_strlen(list->str);
		if (tmp > ret && file_get(list, param) == 1)
			ret = tmp;
		list = list->next;
	}
	return (ret);
}

void	print_space(int nbr)
{
	while (nbr-- > 0)
		ft_putchar(' ');
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
