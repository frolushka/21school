/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 00:37:22 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 23:05:25 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

t_dots	*t_dots_init(int const x, int const y)
{
	t_dots	*res;

	if (!(res = (t_dots *)malloc(sizeof(*res))))
		return (NULL);
	res->local = NULL;
	res->cam = NULL;
	res->screen = NULL;
	res->xc = x;
	res->yc = y;
	return (res);
}

/*	TODO
*/

void	t_dots_del(t_dots **d)
{
	int	i;
	int	count;

	if (!d || !*d)
		return ;
	i = -1;
	count = (*d)->xc * (*d)->yc;
	while (++i < count)
		free((*d)->local[i]);
	free(*d);
	*d = NULL;
}
