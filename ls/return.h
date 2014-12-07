#ifndef RETURN_H
# define RETURN_H

typedef struct  dirent  t_dir;

int		ft_ls_return_rights(t_dir *file);
char	*ft_ls_return_file(char *str);
char	*ft_ls_return_path(char *str);
void	ft_ls_return_new_path(char **dst, char *str1, char *str2);

#endif
