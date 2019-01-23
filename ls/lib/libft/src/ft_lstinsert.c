/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:52:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 01:23:59 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <stdio.h>

/*	1	n1 > n2
 *	0	n1 == n2
 *	-1	n1 < n2
 */

void	ft_lstinsert(t_list **alst, t_list *node,
	int (*comp)(void *n1, void *n2))
{
	t_list	*cur;

	if (!alst || !comp)
		return ;
	if (!*alst)
		*alst = node;
	else if (comp((*alst)->content, node->content) > 0)
	{
		cur = *alst;
		while (cur->next && comp(cur->content, node->content) > 0)
			cur = cur->next;
		node->next = cur->next;
		cur->next = node;
	}
	else
	{
		node->next = *alst;
		*alst = node;
	}
	// printf("lst now:\n");
	// cur = *alst;
	// while (cur)
	// {
	// 	printf("   %s\n", ((struct dirent *)cur->content)->d_name);
	// 	cur = cur->next;
	// }
	// printf("\n");
}
