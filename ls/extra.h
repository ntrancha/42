#ifndef EXTRA_H
# define EXTRA_H
# include "recup.h"
# include "list.h"
# include "param.h"

char    *get_group(t_stat s);
int     file_ok(t_list *list, t_param *param);
char    *get_user(t_stat s);

#endif
