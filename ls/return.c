/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 13:58:44 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/05 13:58:44 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <grp.h> 
#include <pwd.h>
#include <libft.h> 
#include "dos.h"
#include "recup.h"
#include "param.h"

int         ft_ls_return_rights(t_dir *fichierLu)
{
    int     ret;
    t_stat  m;

    ret = 0;
    if (lstat(fichierLu->d_name,&m) != 0)
        if (stat(fichierLu->d_name,&m) != 0)
            return (0);
    if ((m.st_mode & S_IRUSR) != 0)
        ret += 400;
    if ((m.st_mode & S_IWUSR) != 0)
        ret += 200;
    if ((m.st_mode & S_IXUSR) != 0)
        ret += 100;
    if ((m.st_mode & S_IRGRP) != 0)
        ret += 40;
    if ((m.st_mode & S_IWGRP) != 0)
        ret += 20;
    if ((m.st_mode & S_IXGRP) != 0)
        ret += 10;
    if ((m.st_mode & S_IROTH) != 0)
        ret += 4;
    if ((m.st_mode & S_IWOTH) != 0)
        ret += 2;
    if ((m.st_mode & S_IXOTH) != 0)
        ret += 1;
    if (S_ISDIR(m.st_mode))
        return (-1);
    return (ret);
}

char        *ft_ls_return_file(char *str)
{
    int     index;
    char    *ret;

    index = ft_strlen(str);
    while (index >= 0)
    {
        if (str[index] == '/')
            return (ft_strsub(str, index + 1, (ft_strlen(str) - index)));
        index--;
    }
    return (ft_strdup(str));
}

char        *ft_ls_return_path(char *str)
{
    char    *ret;
    int     index;
    int     test = 0;

    index = ft_strlen(str);
    while (index-- >= 0 && str[index] == '\0')
    {
        if (str[index] == '/')
            test = 1;
    }
    if (test == 0)
    {
        ret = ft_strnew(2);
        ret[0] = '.';
        ret[1] = '\0';
        return (ret);
    }
    index = ft_strlen(str);
    ret = ft_strdup(str);
    while (index-- > 1)
    {
        if (ret[index] == '/')
        {
            ret[index] = '\0';
            index = 0;
        }
    }
    return (ret);
}
