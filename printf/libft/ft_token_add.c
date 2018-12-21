/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:51:01 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:51:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_token	*ft_token_add(t_token **head, t_token *node)
{
	t_token	*cur;

	if (!head || !node)
		return (NULL);
	if (!*head)
		*head = node;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	return (node);
}
