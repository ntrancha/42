/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:09:54 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 10:26:20 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "dos.h"
#include "param.h"

void		ft_ls_error(char *str, t_param *param)
{
	ft_putstr(param->prog_name);
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr(strerror( errno ));
	ft_putstr("\n");
}

int			ft_ls_test_dir(char *str, t_param *param)
{
	DIR		*dir;

	dir = opendir(str);
	if (dir != NULL)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

int			ft_ls_test_file(char *str, t_param *param)
{
	int		ret;

	ret = open(str, O_RDONLY);
	if (ret != -1)
	{
		close(ret);
		return (1);
	}
	return (0);
}

int			ft_ls_test_dos_next(t_dos *tmp, t_dos **file, t_param *param)
{
	if (ft_ls_test_file(tmp->str, param) == 1)
	{
		param->f++;
		*file = ft_list_dos_new(tmp->str, *file);
		return (1);
	}
	ft_ls_error(tmp->str, param);
	return (0);
}

int			ft_ls_test_dos(t_dos **dos, t_dos **file, t_param *param)
{
	t_dos	*prev;
	t_dos	*tmp;

	prev = NULL;
	tmp = *dos;
	while (tmp != NULL)
	{
		if (ft_ls_test_dir(tmp->str, param) == 0)
		{
			ft_ls_test_dos_next(tmp, file, param);
			if (prev != NULL)
				prev->next = tmp->next;
			else
				*dos = tmp->next;
			ft_strdel(&tmp->str);
			ft_memdel(tmp);
			param->m--;
			return (ft_ls_test_dos(dos, file, param));
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}
