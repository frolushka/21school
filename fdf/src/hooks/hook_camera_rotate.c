/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_camera_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:39:49 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 04:53:20 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	hook_camera_rotate_x(t_cam *cam, float const a)
{
	t_vec3	*axis;

	if (cam->mode == CAM_PER)
		camera_rotate_x(cam, a * cam->sence);
	else
	{
		axis = vec3_new(cam->cam->val[0][0], cam->cam->val[0][1], cam->cam->val[0][2]);
		camera_rotate_custom(cam, cam->piv, axis, a);
		free(axis);
	}
}

void	hook_camera_rotate_y(t_cam *cam, float const a)
{
	t_vec3	*axis;

	// printf("cam mode now %s\n", cam->mode);
	if (cam->mode == CAM_PER)
		camera_rotate_y(cam, a * cam->sence);
	else
	{
		// printf("rotate \n");
		// mtx4_print(cam->cam);
		// printf("\naround point\n");
		// vec3_print(cam->piv);
		// printf("\nand axis\n");
		axis = vec3_new(0, 1, 0);
		// vec3_print(axis);
		camera_rotate_custom(cam, cam->piv, axis, a);
		free(axis);
	}
}
