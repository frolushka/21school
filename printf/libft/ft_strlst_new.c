/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:29:54 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:30:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_strlst	*ft_strlst_new(char *val)
{
	t_strlst	*res;

	if (!val || !(res = (t_strlst *)malloc(sizeof(*res))))
		return (NULL);
	if (!(res->val = ft_strdup(val)))
	{
		free(res);
		return (NULL);
	}
	res->next = NULL;
	return (res);
}
