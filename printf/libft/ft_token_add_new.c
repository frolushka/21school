/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_add_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:53:12 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:54:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_token	*ft_token_add_new(t_token **head, void *c, size_t csize)
{
	t_token	*res;

	if (!(res = ft_token_new(c, csize)))
		return (NULL);
	ft_token_add(head, res);
	return (res);
}