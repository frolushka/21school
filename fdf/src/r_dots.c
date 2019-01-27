/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:38:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 22:38:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_dots(char *fn, t_dots **res)
{
	t_vec2	*size;

	*res = NULL;
	if (!res || !fn || !get_size(fn, &size))
		return (0);
	if (!(*res = t_dots_init(size->x, size->y)))
	{
		free(size);
		return (0);
	}
	free(size);
	if (!(fill_dots(fn, res)))
	{
		t_dots_del(res);
		return (0);
	}
	return (1);
}
