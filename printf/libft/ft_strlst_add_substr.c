/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_add_substr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:24:35 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:35:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_strlst	*ft_strlst_add_substr(t_strlst **head, char *val,
			unsigned int start, size_t len)
{
	t_strlst	*res;

	if (!(res = ft_strlst_new(ft_strsub(val, start, len))))
		return (NULL);
	ft_strlst_add(head, res);
	return (res);
}