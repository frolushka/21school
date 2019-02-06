/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:50:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 02:53:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"
#include <stdio.h>

static int 		color_lerp(int c1, int c2, float step)
{
	int	res;

	res = 0;
	res |= (((int)((((int)((c2 >> 16) & 0xFF)) -
		((int)((c1 >> 16) & 0xFF))) * step)) +
		((c1 >> 16) & 0xFF)) << 16;
	res |= (((int)((((int)((c2 >> 8) & 0xFF)) -
		((int)((c1 >> 8) & 0xFF))) * step)) +
		((c1 >> 8) & 0xFF)) << 8;
	res |= (((int)((((int)((c2 >> 0) & 0xFF)) -
		((int)((c1 >> 0) & 0xFF))) * step)) +
		((c1 >> 0) & 0xFF)) << 0;
	return (res);
}

void			image_draw_line(t_mlx const *mlx, t_vec2 const *v1,
				t_vec2 const *v2, t_vec2 const *c)
{
	t_vec2 *d = vec2_new(ft_abs(v2->x - v1->x), ft_abs(v2->y - v1->y));
	t_vec2 *s = vec2_new(ft_sign(v2->x - v1->x), ft_sign(v2->y - v1->y));
	int err = (d->x > d->y ? d->x : -d->y) / 2;
	int e2;
	int xt = v1->x;
	int	yt = v1->y;
	while (xt != v2->x || yt != v2->y)
	{
		image_set_pixel(mlx->image, xt, yt,
			color_lerp(c->x, c->y,
				ft_fabs(sqrt(xt * xt + yt * yt) - sqrt(v1->x * v1->x + v1->y * v1->y)) /
				ft_fabs(sqrt(v2->x * v2->x + v2->y * v2->y) - sqrt(v1->x * v1->x + v1->y * v1->y))
			));
		e2 = err;
		if (e2 > -d->x)
		{
			err -= d->y;
			xt += s->x;
		}
		if (e2 < d->y)
		{
			err += d->x;
			yt += s->y;
		}
	}
	free(d);
	free(s);
}
