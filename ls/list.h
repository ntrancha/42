/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 09:04:55 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/24 10:48:02 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct	s_list			t_list;
typedef struct	s_stats			t_stats;
typedef struct	s_time			t_time;
typedef struct	s_list_repere	t_llist;

struct			s_stats
{
	int         hidden;
    int         mode;
	char        *user;
    char        *group;
    unsigned char       type;
};

struct			s_time
{
	int			size;
	long		atime;
	long		mtime;
	long		ctime;
};

struct			s_list
{
	char		*str;
	t_time		*time;
	t_stats		*stats;
	t_list		*next;
	t_list		*previous;
};

struct			s_list_repere
{
	t_list		*start;
	t_list		*end;
	t_llist		*next;
	int			length;
	int			size_link;
	int			size_user;
	int			size_group;
	int			size_size;
	int			size_date;
	int			size_year;
	int			size_minor;
	int			size_major;
	char		*path;
};

t_llist			*ft_list_create(char *path);
t_list			*ft_list_add_malloc(void);
t_llist			*ft_list_add_complete(t_llist *repere, int size);
t_llist			*ft_list_add(t_llist *repere, char *valeur, int size);
t_llist			*ft_list_add_dir(t_llist *racine, char *path);

#endif
