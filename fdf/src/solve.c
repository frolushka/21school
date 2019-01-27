/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:23:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/24 21:00:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_dots(const t_mlx *c, t_dots **d)
{
	int	i;
	int	j;
	int	xc;
	int	yc;

	if (!d || !*d)
		return ;
	xc = (*d)->xc;
	yc = (*d)->yc;
	i = -1;
	while (++i < yc)
	{
		j = -1;
		while (++j < xc)
		{
			// if (j != xc - 1)
			// 	draw_line(c, (*d)->screen[i * xc + j],
			// 		(*d)->screen[i * xc + j + 1], (int)(*d)->local[i * xc + j]->w,
			// 		(int)(*d)->local[i * xc + j + 1]->w);
			// if (i != yc - 1)
			// 	draw_line(c, (*d)->screen[i * xc + j],
			// 		(*d)->screen[(i + 1) * xc + j], (int)(*d)->local[i * xc + j]->w,
			// 		(int)(*d)->local[(i + 1) * xc + j]->w);
			(((j != xc - 1) && (((*d)->cam[i * xc + j]->z < 0) || ((*d)->cam[i * xc + j + 1]->z < 0)))
			 ? draw_line(c, (*d)->screen[i * xc + j],
				(*d)->screen[i * xc + j + 1], (int)(*d)->local[i * xc + j]->w,
				(int)(*d)->local[i * xc + j + 1]->w) : 0);
			(((i != yc - 1) && (((*d)->cam[i * xc + j]->z < 0) || ((*d)->cam[i * xc + j + 1]->z < 0)))
			 ? draw_line(c, (*d)->screen[i * xc + j],
			(*d)->screen[(i + 1) * xc + j], (int)(*d)->local[i * xc + j]->w,
			(int)(*d)->local[(i + 1) * xc + j]->w) : 0);
		}
	}
}

#include <stdio.h>

void	solve_dots(t_dots *dots, const t_cam *cam)
{
	int	i;
	int	c;

	i = -1;
	c = dots->xc * dots->yc;
	while (++i < c)
	{
		world_to_cam(dots->local[i], cam->cam, dots->cam[i]);
		///mtx4_print(cam->cam);
		//printf("\n");
		// printf("after: point (%f, %f, %f) now: ", dots->local[i]->x, dots->local[i]->y, dots->local[i]->z);
		// vec3_print(dots->cam[i]);
		// printf("\n");
		// wrdtocam(dots->local[i], cam->camops, dots->cam[i]);
		if (cam->mode == CAM_ISO)
			iso_camtoscreen(dots->cam[i], dots->screen[i]);
		else
			persp_camtoscreen(dots->cam[i], dots->screen[i], cam);
	}
}
// void	solve_dots(t_dots *dots, const t_cam *cam)
// {
// 	int	i;
// 	int	c;

// 	i = -1;
// 	c = (*dots)->xc * (*dots)->yc;
// 	while (++i < c)
// 	{
// 		wrdtocam((*dots)->local[i], cam->camops, (*dots)->cam[i]);
// 		//persp_camtoscreen((*dots)->cam[i], (*dots)->screen[i], cam);
// 		iso_camtoscreen((*dots)->cam[i], (*dots)->screen[i]);
// 	}
// }
