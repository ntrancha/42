#ifndef EXTRA_H
# define EXTRA_H
# include <sys/stat.h>
# include "recup.h"
# include "list.h"
# include "param.h"

t_llist	*recursive_path(t_llist *root, t_param *param, char *str);
char    *get_group(t_stat s);
int     file_ok(t_list *list, t_param *param);
char    *get_user(t_stat s);
void	print_mode(mode_t m);

#endif
