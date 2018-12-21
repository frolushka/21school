/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 01:31:55 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:35:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlst_print(t_strlst *head)
{
	t_strlst	*cur;
	int			res;
	int			i;

	if (!head)
		return (0);
	cur = head;
	res = 0;
	while (cur)
	{
		i = -1;
		while (cur->val[++i])
			write(1, &(cur->val[i]), 1);
		res += i;
		cur = cur->next;
	}
	return (res);
}
