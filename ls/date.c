/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 17:54:55 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/07 17:54:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*date_year(char *str)
{
	char	*ret;

	ret = ft_strsub(str, (ft_strlen(str) - 5), 4);
	return (ret);
}

char		*date_hour(char *str)
{
	char	*ret;

	ret = ft_strsub(str, (ft_strlen(str) - 14), 5);
	return (ret);
}

char		*date_date(char *str)
{
	char	*ret;

	ret = ft_strsub(str, 8, ft_strlen(str) - 23);
	return (ret);
}

char		*date_mois(char *str)
{
	char	*ret;

	ret = ft_strsub(str, 4, ft_strlen(str) - 22);
	return (ret);
}
