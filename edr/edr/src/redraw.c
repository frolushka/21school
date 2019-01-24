/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:17:26 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/24 21:18:08 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include <stdio.h>

void	redraw(const t_mlx *c, t_dots *dots, const t_cam *cam)
{
	image_clear(c->image);
	// mlx_clear_window(c->mlx, c->win);
	// mtx4_rev(cam->cam, cam->camops);
	solve_dots(dots, cam);
		// printf("loc: (%f, %f, %f, %f), cam: (%f, %f, %f), screen: (%d, %d)\n", (*dots)->local[0]->x, (*dots)->local[0]->y, (*dots)->local[0]->z, (*dots)->local[0]->w, (*dots)->cam[0]->x,  (*dots)->cam[0]->y,  (*dots)->cam[0]->z,  (*dots)->screen[0]->x,  (*dots)->screen[0]->y);

	connect_dots(c, &dots);
	mlx_put_image_to_window(c->mlx, c->win, c->image->image, 0, 0);
}
