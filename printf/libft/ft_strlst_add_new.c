/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_add_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:30:08 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:31:03 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_strlst	*ft_strlst_add_new(t_strlst **head, char *val)
{
	t_strlst	*res;

	if (!(res = ft_strlst_new(val)))
		return (NULL);
	ft_strlst_add(head, res);
	return (res);
}
