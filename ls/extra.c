/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:54:46 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/02 13:54:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "recup.h"
#include "list.h"
#include "param.h"
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

int			ft_ls_path(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 0)
		return (-1);
	if (len == 1)
	{
		if (str[0] == '/')
			return (1);
		return (3);
	}
	if (str[len - 1] == '/')
		str[len - 1] = '\0';
	if (str[0] == '/')
		return (2);
	return (3);
}

char		*ft_ls_add_path(char **fichier, char *path)
{
	char	*tmp;

	tmp = ft_strdup(*fichier);
	if (tmp == NULL)
		return (NULL);
	ft_strdel(fichier);
	*fichier = ft_strjoin(path, tmp);
	return (*fichier);
}

char    *get_group(t_stat s)
{
    t_pass      *pass;

    pass = getpwuid(s.st_gid);
    if (pass == NULL)
        return (NULL);
    return (pass->pw_name);
}

int     file_get(t_list *list, t_param *param)
{
    if (param->a == 1)
        return (1);
    else
        if (ft_strcmp(list->str, "..") != 0)
            if (ft_strcmp(list->str, ".") != 0)
                return (1);
    return (0);
}

char    *get_user(t_stat s)
{
    t_pass      *pass;

    pass = getpwuid(s.st_uid);
    return (pass->pw_name);
}
