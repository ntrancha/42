#ifndef DISPLAY_H
# define DISPLAY_H
# include "param.h"
# include "list.h"
# include "dos.h"

int		ft_ls_display_std(char *str, t_param *param, t_llist *root);
void	ft_ls_display_file(t_dos **file, t_param *param);
int		ft_ls_display_list(t_list *fichier, t_llist *root, t_param *param);
void	ft_ls_display_next(t_llist *list, t_param *param, t_list *fichier);
void	ft_ls_display(t_llist *list, t_param *param);

#endif
