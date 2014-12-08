#ifndef PRINT_SIZE_H
# define PRINT_SIZE_H
# include <sys/stat.h>
# include "param.h"
# include "list.h"
# include "recup.h"

void   print_size_atime(t_llist *root, t_stat s);
void   print_size_mtime(t_llist *root, t_stat s);
void   print_size_ctime(t_llist *root, t_stat s);

#endif
