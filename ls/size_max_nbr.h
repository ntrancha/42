#ifndef SIZE_MAX_NBR_H
# define SIZE_MAX_NBR_H
# include "param.h"
# include "list.h"

int     ft_nbrlen(int nbr);
int     date_max_len(t_llist *root, int ret, t_param *param);
int     size_max_len(t_llist *root, int ret, t_param *param);
int     links_max_len(t_llist *root, int ret, t_param *param);
int     minor_max_len(t_llist *root, int ret, t_param *param);

#endif
