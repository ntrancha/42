#ifndef EXTRA_H
# define EXTRA_H
# include "recup.h"
# include "list.h"
# include "param.h"

char        *ft_ls_add_path(char **fichier, char *path);;
int         ft_ls_path(char *str);
char    *get_group(t_stat s);
int     file_get(t_list *list, t_param *param);
char    *get_user(t_stat s);

#endif
