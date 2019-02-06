/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_fill_cb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:12:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 04:06:45 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static float	dots_fill_cb_det(float const val[4][4])
{
	return (val[0][0] * val[1][1] * val[2][2] +
		val[0][2] * val[1][0] * val[2][1] +
		val[0][1] * val[1][2] * val[2][0] -
		val[0][2] * val[1][1] * val[2][0] -
		val[0][0] * val[1][2] * val[2][1] -
		val[0][1] * val[1][0] * val[2][2]);
}

static void		dots_fill_cb_col(float val[4][4], t_vec3 const *v, int const j)
{
	val[0][j] = v->x;
	val[1][j] = v->y;
	val[2][j] = v->z;
}

void			dots_fill_cb(const t_vec4 *p, const t_mtx4 *c, t_vec3 *res)
{
	t_mtx4	*temp;
	t_vec3	*l;
	float	det;

	l = vec3_new(-c->val[3][0] + p->x, -c->val[3][1] + p->y, -c->val[3][2] + p->z);
	det = dots_fill_cb_det(c->val);
	if (ft_fabs(det) < 0.00001f)
	{
		res = vec3_new(0, 0, 0);
		return ;
	}
	temp = mtx4_copy(c);
	dots_fill_cb_col(temp->val, l, 0);
	res->x = dots_fill_cb_det(temp->val) / det;
	free(temp);
	temp = mtx4_copy(c);
	dots_fill_cb_col(temp->val, l, 1);
	res->y = dots_fill_cb_det(temp->val) / det;
	free(temp);
	temp = mtx4_copy(c);
	dots_fill_cb_col(temp->val, l, 2);
	res->z = dots_fill_cb_det(temp->val) / det;
	free(temp);
}
