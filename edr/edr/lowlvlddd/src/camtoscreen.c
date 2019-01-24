/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camtoscreen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 06:20:46 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 07:28:29 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

void	iso_camtoscreen(const t_vec3 *point, t_vec2 *res)
{
	res->x = (int)(point->x * UNIT);
	res->y = (int)(point->y * UNIT);
	// printf("screen now: ");
	// vec2_print(res);
	// printf("\n");
}

void	persp_camtoscreen(t_vec3 *point, t_vec2 *res, const t_cam *cam)
{
	if (point->z == 0.0f)
		return ;
	res->x = SCREEN_X / 2 + (int)(((float)(point->x)
		/ (float)(point->z * cam->focus)) * UNIT);
	res->y = SCREEN_Y / 2 + (int)(((float)(point->y)
		/ (float)(point->z * cam->focus)) * UNIT);
	//vec2_print(res);
	//printf("\n\n");
}
