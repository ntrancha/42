#ifndef DISPLAY_LIST_H
# define DISPLAY_LIST_H
# include "param.h"
# include "list.h"
# include "dos.h"
# include "display.h"
    
int     display_std(char *str, t_param *param, t_llist *root);
void    display_file(t_dos **file, t_param *param);
int     display_list(t_list *fichier, t_llist *root, t_param *param);
    
#endif
