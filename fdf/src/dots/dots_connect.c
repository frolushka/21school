/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:23:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 23:44:23 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_out(const t_dots *d, const int d1, const int d2)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = d->sb[d1]->x;
	x2 = d->sb[d2]->x;
	y1 = d->sb[d1]->y;
	y2 = d->sb[d2]->y;
	if ((x1 < 0 && x2 < 0) || (x1 > SCREEN_X && x2 > SCREEN_X)
		|| (y1 < 0 && y2 < 0) || (y1 > SCREEN_Y && y2 > SCREEN_Y)
		|| (d->cb[d1]->z > 0 && d->cb[d2]->z > 0))
		return (1);
	return (0);
}

static int	swap_if_d2_less(t_vec2 **d1, t_vec2 **d2,
	const float d1v, const float d2v)
{
	t_vec2 *t;

	if (d1v <= d2v)
		return (0);
	t = *d1;
	d1 = d2;
	d2 = &t;
	return (1);
}

static void	oclude_x(t_vec2 *d1, t_vec2 *d2)
{
	if ((d1->y > 0 && d1->y < SCREEN_Y)
		&& (d2->y > 0 && d2->y < SCREEN_Y))
		return ;
	if (abs(d2->x - d1->x) <= 2)
	{
		if(d1->y < 0 || d1->y > SCREEN_Y)
			d1->y = ((d1->y < 0) ? 0 : SCREEN_Y);
		if(d2->y < 0 || d2->y > SCREEN_Y)
			d2->y = ((d2->y < 0) ? 0 : SCREEN_Y);
		return ;
	}
	if (d2->y > SCREEN_Y)
	{
		d2->x = d1->x + (int)((float)
			((d2->x - d1->x) * (SCREEN_Y - d1->y))
			/ (float)(d2->y - d1->y));
		d2->y = SCREEN_Y;
	}
	if (d1->y > SCREEN_Y)
	{
		d1->x = d1->x + (int)((float)
			((d2->x - d1->x) * (SCREEN_Y - d1->y))
			/ (float)(d2->y - d1->y));
		d1->y = SCREEN_Y;
	}
	if (d2->y < 0)
	{
		d2->x = d2->x + (int)((float)
			((d2->x - d1->x) * d2->y)
			/ (float)(d1->y - d2->y));
		d2->y = 0;
	}
	if (d1->y < 0)
	{
		d1->x = d2->x + (int)((float)
			((d2->x - d1->x) * d2->y)
			/ (float)(d1->y - d2->y));
		d1->y = 0;
	}
}

static void	oclude_y(t_vec2 *d1, t_vec2 *d2)
{
	if ((d1->x > 0 && d2->x < SCREEN_X)
		&& (d2->x > 0 && d2->x < SCREEN_X))
		return ;
	if (abs(d2->y - d1->y) <= 2)
	{
		if(d1->x < 0 || d1->x > SCREEN_X)
			d1->x = ((d1->x < 0) ? 0 : SCREEN_X);
		if(d2->x < 0 || d2->x > SCREEN_X)
			d2->x = ((d2->x < 0) ? 0 : SCREEN_X);
		return ;
	}
	if (d2->x > SCREEN_X)
	{
		d2->y = d2->y + (int)((float)
			((d2->y - d1->y) * (SCREEN_X - d2->x))
			/ (float)(d2->x - d1->x));
		d2->x = SCREEN_X;
	}
	if (d1->x > SCREEN_X)
	{
		d1->y = d2->y - (int)((float)
			((d2->y - d1->y) * (SCREEN_X - d2->x))
			/ (float)(d2->x - d1->x));
		d1->x = SCREEN_X;
	}
	if (d2->x < 0)
	{
		d2->y = d2->y + (int)((float)
			((d2->y - d1->y) * d2->x)
			/ (float)(d1->x - d2->x));
		d2->x = 0;
	}
	if (d1->x < 0)
	{
		d1->y = d2->y + (int)((float)
			((d2->y - d1->y) * d2->x)
			/ (float)(d1->x - d2->x));
		d1->x = 0;
	}
}

static void	draw_with_oclusion(const t_mlx *c, t_dots *d,
	int d1, int d2)
{
	t_vec2	*v1;
	t_vec2	*v2;
	t_vec2	*cv;

	if (check_out(d, d1, d2))
		return ;
	if (d->cb[d2]->z > 0 || d->cb[d1]->z > 0)
		return ;
	v1 = vec2_copy(d->sb[d1]);
	v2 = vec2_copy(d->sb[d2]);
	cv = vec2_new((int)d->wb[d1]->w, (int)d->wb[d2]->w);
	swap_if_d2_less(&v1, &v2, (float)v2->x, (float)v1->x);
	oclude_x(v1, v2);
	swap_if_d2_less(&v1, &v2, (float)v2->y, (float)v1->y);
	oclude_y(v1, v2);
	image_draw_line(c, v1, v2, cv);
	free(cv);
	free(v1);
	free(v2);
}

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
			if (j != xc - 1)
				draw_with_oclusion(c, d, i * xc + j, i * xc + j + 1);
			if (i != yc - 1)
				draw_with_oclusion(c, d, i * xc + j, (i + 1) * xc + j);
		}
	}
}
