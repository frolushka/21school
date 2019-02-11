/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:50:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/11 18:49:44 by edraugr-         ###   ########.fr       */
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

// ЩА БУИТ МЯСО

// static int iPartOfNumber(float x)
// {
//     return (int)x;
// }

// //returns fractional part of a number
// static float fPartOfNumber(float x)
// {
//     if (x>0) return x - iPartOfNumber(x);
//     else return x - (iPartOfNumber(x)+1);

// }

// //returns 1 - fractional part of number
// static float rfPartOfNumber(float x)
// {
//     return 1 - fPartOfNumber(x);
// }

// static int	color_set_brightness(int c, float br)
// {
// 	int r = (c & 0xFF0000) >> 16;
// 	int g = (c & 0xFF00) >> 8;
// 	int b = (c & 0xFF);

// 	r *= br;
// 	g *= br;
// 	c *= br;
// 	return (r << 16 | g << 8 | b);
// }

void			image_draw_line(t_mlx const *mlx, t_vec2 const *v1,
				t_vec2 const *v2, t_vec2 const *c)
{
	// t_vec2	*v1c = vec2_copy(v1);
	// t_vec2	*v2c = vec2_copy(v2);

	// int	steep = ft_abs(v2->y - v1->y) > ft_abs(v2->x - v1->x);

	// if (steep)
	// {
	// 	ft_swap(&(v1c->x), &(v1c->y));
	// 	ft_swap(&(v2c->x), &(v2c->y));
	// }
	// if (v1c->x > v2c->x)
	// {
	// 	ft_swap(&(v1c->x), &(v2c->x));
	// 	ft_swap(&(v1c->y), &(v2c->y));
	// }

	// float	dx = v2c->x - v1c->x;
	// float	dy = v2c->y - v1c->y;
	// float	g = dy / dx;
	// if (dx == 0.0f)
	// 	g = 1;

	// int xpxl1 = v1c->x;
	// int xpxl2 = v2c->x;
	// float y = v1c->y;

	// if (steep)
    // {
    //     int x;
    //     for (x = xpxl1 ; x <=xpxl2 ; x++)
    //     {
	// 		int color = color_lerp(c->x, c->y,
	//  			ft_fabs(sqrt(x * x + y * y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y)) /
	// 			ft_fabs(sqrt(v2c->x * v2c->x + v2c->y * v2c->y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y))
	// 		);
	// 		int c1 = color_set_brightness(color, rfPartOfNumber(y));
	// 		image_set_pixel(mlx->image, iPartOfNumber(y), x, c1);
	// 		int c2 = color_set_brightness(color, fPartOfNumber(y));
	// 		image_set_pixel(mlx->image, iPartOfNumber(y) - 1, x, c2);
    //         y += g;
    //     }
    // }
    // else
    // {
    //     int x;
    //     for (x = xpxl1 ; x <=xpxl2 ; x++)
    //     {
    //         int color = color_lerp(c->x, c->y,
	//  			ft_fabs(sqrt(x * x + y * y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y)) /
	// 			ft_fabs(sqrt(v2c->x * v2c->x + v2c->y * v2c->y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y))
	// 		);
	// 		int c1 = color_set_brightness(color, rfPartOfNumber(y));
	// 		image_set_pixel(mlx->image, x, iPartOfNumber(y), c1);
	// 		int c2 = color_set_brightness(color, fPartOfNumber(y));
	// 		image_set_pixel(mlx->image, x, iPartOfNumber(y) - 1, c2);
    //         y += g;
    //     }
    // }
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
