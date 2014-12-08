#ifndef SIZE_MAX_STR_H
# define SIZE_MAX_STR_H
# include "param.h"
# include "list.h"

int     group_max_len(t_llist *root, int ret, int temp, t_param *param);
int     major_max_len(t_llist *root, int ret, t_param *param);
int     user_max_len(t_llist *root, int ret, int temp, t_param *param);
int     year_max_len(t_llist *root, int ret, t_param *param);
int     strs_max_len(t_llist *root, t_param *param);

#endif
