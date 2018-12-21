/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:31:29 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:31:41 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_strlst	*ft_strlst_add(t_strlst **head, t_strlst *node)
{
	t_strlst	*cur;

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
