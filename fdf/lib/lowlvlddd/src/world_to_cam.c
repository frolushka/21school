/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_to_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 06:30:24 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 07:28:40 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"
#include <stdio.h>

static float	get_det(t_mtx4 const *m)
{
	return (m->val[0] * m->val[5] * m->val[10] +
		m->val[2] * m->val[4] * m->val[9] +
		m->val[1] * m->val[6] * m->val[8] -
		m->val[2] * m->val[5] * m->val[8] -
		m->val[0] * m->val[6] * m->val[9] -
		m->val[1] * m->val[4] * m->val[10]);
}

static void		set_column(t_mtx4 *m, t_vec3 const *v, int const j)
{
	m->val[j] = v->x;
	m->val[4 + j] = v->y;
	m->val[8 + j] = v->z;
}

void			world_to_cam(const t_vec4 *p, const t_mtx4 *c, t_vec3 *res)
{
	t_vec3	*l;

	l = vec3_new(-c->val[12] + p->x, -c->val[13] + p->y, -c->val[14] + p->z);
	float det = get_det(c);
	if (fabsf(det) < 0.00001f)
	{
		res = vec3_new(0, 0, 0);
		return ;
	}
	t_mtx4 *temp = mtx4_cpy(c);
	set_column(temp, l, 0);
	float det1 = get_det(temp);
	temp = mtx4_cpy(c);
	set_column(temp, l, 1);
	float det2 = get_det(temp);
	temp = mtx4_cpy(c);
	set_column(temp, l, 2);
	float det3 = get_det(temp);
	res->x = det1 / det;
	res->y = det2 / det;
	res->z = det3 / det;
	// printf("before: ");
	// vec3_print(res);
	// printf("\n");
}
