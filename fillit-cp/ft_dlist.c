/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 00:34:08 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/13 01:26:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlst_new(int const val)
{
	t_dlist	*res;

	if (!(res = (t_dlist *)malloc(sizeof(*res))))
		return (NULL);
	res->value = val;
	res->next = NULL;
	return (res);
}

t_dlist	*ft_dlist_get(t_dlist *root, int i)
{
	t_dlist	*res;

	if (!root || i < 0)
		return (NULL);
	res = root;
	while (i-- > 0 && res)
		res = res->next;
	return (res);
}

int		ft_dlst_pushback(t_dlist **root, t_dlist *node)
{
	t_dlist	*cur;

	if (!root)
		return (-1);
	if (!*root)
		*root = node;
	else
	{
		cur = *root;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	return (0);
}

int		ft_dlst_clear(t_dlist **root)
{
	t_dlist	*cur;
	t_dlist	*tmp;

	if (!root)
		return (-1);
	cur = *root;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	return (0);
}

int		ft_dlst_size(t_dlist *root)
{
	t_dlist	*cur;
	int		size;

	if (!root)
		return (-1);
	cur = root;
	size = 0;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return (size);
}
