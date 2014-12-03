/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:17:55 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 10:11:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

int	        ft_ls_test_dos(t_dos **dos, t_dos **file, t_param *param);
int         ft_ls_test_file(char *str);
int         ft_ls_test_dir(char *str);
void        ft_ls_error(char *str);

#endif
