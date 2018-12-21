/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:48:45 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:50:22 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_token	*ft_token_new(void *c, size_t csize)
{
	t_token	*res;

	if (!(res = (t_token *)malloc(sizeof(*res))))
		return (NULL);
	if (!c)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(res->content = malloc(csize)))
		{
			free(res);
			return (NULL);
		}
		ft_memcpy(res->content, c, csize);
		res->content_size = csize;
	}
	res->next = NULL;
	return (res);
}