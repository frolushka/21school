/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots4_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 08:15:52 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/09 12:04:09 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec4	**dots4_cpy(const t_vec4 **src, const int xc, const int yc)
{
	int		i;
	int		j;
	t_vec4	**res;

	if (!(res = (t_vec4 **)malloc(sizeof(t_vec4 *) * xc * yc)))
		return (NULL);
	i = -1;
	while(++i < yc)
	{
		j = -1;
		while(++j < xc)
			res[i * yc + j] = vec4_copy(src[i * yc + j]);
	}
	return (res);
}
