#ifndef DOS_H
# define DOS_H

typedef struct  s_dir           t_dos;

struct          s_dir
{
    char        *str;
    t_dos       *next;
};

t_dos	*ft_list_dos_create(char *path);
t_dos	*ft_list_dos_new(char *path, t_dos *racine);
int		ft_list_dos_sort(t_dos **racine, int sort);
void	ft_list_dos_del(t_dos **racine);
t_dos	*ft_list_dos_free(t_dos **racine);

#endif
