/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_set_rot_axis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 01:14:11 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 01:27:16 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

t_mtx4	*mtx4_set_rot_axis(const t_vec3 *v, const float a)
{
	float	c;
	float	s;
	t_mtx4	*res;

	res = mtx4_init(0.0f);
	c = cosf(((a * ((float)M_PI)) / 180.0f));
	s = sinf(((a * ((float)M_PI)) / 180.0f));
	res->val[0] = c + (1 - c) * v->x * v->x;
	res->val[1] = (1 - c) * v->x * v->y - s * v->z;
	res->val[2] = (1 - c) * v->x * v->z + s * v->y;
	res->val[4] = (1 - c) * v->x * v->y + s * v->z;
	res->val[5] = c + (1 - c) * v->y * v->y;
	res->val[6] = (1 - c) * v->z * v->y - s * v->x;
	res->val[8] = (1 - c) * v->x * v->z - s * v->y;
	res->val[9] = (1 - c) * v->z * v->y + s * v->x;
	res->val[10] = c + (1 - c) * v->z * v->z;
	return (res);
}
