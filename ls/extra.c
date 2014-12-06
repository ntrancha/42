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
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

int			ft_ls_path(char *str)
{
	int		*ret;
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
