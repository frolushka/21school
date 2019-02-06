/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_fill_sb_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:29:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/04 09:41:57 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	dots_fill_sb_per(t_vec3 *point, t_vec2 *res, const t_cam *cam)
{
	float s_x, s_y, n_x, n_y;

	if (ft_fabs(point->z) < 0.001f)
	{
	 	s_x = point->x;
		s_y = point->y;
	}
	else
	{
		s_x = point->x / (-point->z * cam->focus);
		s_y = point->y / (-point->z * cam->focus);
	}
	n_x = (s_x + 1920 / 2) / 1920.0f;
	n_y = (s_y + 1080 / 2) / 1080.0f;
	res->x = (int)(s_x * 1920.0f);
	res->y = (int)((1.0f - s_y) * 1080.0f);
}
