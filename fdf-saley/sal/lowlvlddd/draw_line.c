/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 12:10:13 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/25 22:59:01 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

static void	draw(const t_config *c, t_vector2 p0, t_vector2 p1, const int col)
{
	double	h;
	int		dx;
	int		dy;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	h = 0;
	while ((dx >= 0 ? (p0.x < p1.x) : (p0.x > p1.x)))
	{
		mlx_pixel_put(c->mlx_ptr, c->win_ptr, p0.x, p0.y, col);
		h += ((double)ABS(dy)) / ((double)ABS(dx));
		p0.y += h <= 0.5 ? 0 : SIGN(dy);
		h -= h > 0.5 ? 1 : 0;
		p0.x += SIGN(dx);
	}
}

static void	draw_rev(const t_config *c, t_vector2 p0,
		t_vector2 p1, const int col)
{
	double	h;
	int		dx;
	int		dy;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	h = 0;
	while ((dx >= 0 ? (p0.x < p1.x) : (p0.x > p1.x)))
	{
		mlx_pixel_put(c->mlx_ptr, c->win_ptr, p0.y, p0.x, col);
		h += ((double)ABS(dy)) / ((double)ABS(dx));
		p0.y += h <= 0.5 ? 0 : SIGN(dy);
		h -= h > 0.5 ? 1 : 0;
		p0.x += SIGN(dx);
	}
}

int			ddd_draw_line(const t_config *c, const t_info *inp)
{
	t_vector2	p0;
	t_vector2	p1;

	p0 = *(t_vector2 *)(inp->content[0]);
	p1 = *(t_vector2 *)(inp->content[1]);
	if ((float)((float)ABS((p1.y - p0.y)) / (float)ABS((p1.x - p0.x))) > 1)
	{
		ft_swap(&p0.x, &p0.y);
		ft_swap(&p1.x, &p1.y);
		draw_rev(c, p0, p1, inp->color);
	}
	else
		draw(c, p0, p1, inp->color);
	return (1);
}
