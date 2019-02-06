/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:23:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 01:50:42 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dots_connect(t_dots *d, const t_mlx *c)
{
	int	i;
	int	j;
	int	xc;
	int	yc;

	xc = d->xc;
	yc = d->yc;
	i = -1;
	while (++i < yc)
	{
		j = -1;
		while (++j < xc)
		{
			((j != xc - 1)
			//		&& ((d->cb[i * xc + j]->z > 0) || (d->cb[i * xc + j + 1]->z > 0))
				)
				? image_draw_line(c, d->sb[i * xc + j],
					d->sb[i * xc + j + 1], vec2_new((int)d->wb[i * xc + j]->w,
					(int)d->wb[i * xc + j + 1]->w))
				: 0;
			((i != yc - 1)
			//		&& ((d->cb[i * xc + j]->z > 0) || (d->cb[i * xc + j + 1]->z > 0))
					)
				? image_draw_line(c, d->sb[i * xc + j],
					d->sb[(i + 1) * xc + j], vec2_new((int)d->wb[i * xc + j]->w,
					(int)d->wb[(i + 1) * xc + j]->w))
				: 0;
		}
	}
}
