#ifndef OPTION_H
# define OPTION_H
# include "recup.h"
# include <sys/stat.h>

typedef struct winsize	win;

void	option_carac(t_stat s, t_param *param);
void        option_list(mode_t m);
int        option_inode(char *file, char*path);
void    option_commas(t_list *file, t_param *param, char *str);

#endif
