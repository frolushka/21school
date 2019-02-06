/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_fill_cb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:12:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 11:15:02 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

// static float	dots_fill_cb_det(float const val[4][4])
// {
// 	return (val[0][0] * val[1][1] * val[2][2] -
// 		val[0][0] * val[1][2] * val[2][1] +
// 		val[0][1] * val[1][2] * val[2][0] -
// 		val[0][1] * val[1][0] * val[2][2] +
// 		val[0][2] * val[1][0] * val[2][1] -
// 		val[0][2] * val[1][1] * val[2][0]);
// }

// static void		dots_fill_cb_inv(float const val[4][4], float res[4][4], float det)
// {
// 	res[0][0] = (val[1][1] * val[2][2] - val[1][2] * val[2][1]) / det;
// 	res[1][1] = (val[0][0] * val[2][2] - val[0][2] * val[2][0]) / det;
// 	res[2][2] = (val[0][0] * val[1][1] - val[0][1] * val[1][0]) / det;
// 	res[2][0] = (val[1][0] * val[2][1] - val[1][1] * val[2][0]) / det;
// 	res[0][2] = (val[0][1] * val[1][2] - val[0][2] * val[1][1]) / det;
// 	res[0][1] = -(val[0][1] * val[2][2] - val[0][2] * val[2][1]) / det;
// 	res[1][0] = -(val[1][0] * val[2][2] - val[1][2] * val[2][0]) / det;
// 	res[1][2] = -(val[0][0] * val[1][2] - val[0][2] * val[1][0]) / det;
// 	res[2][1] = -(val[0][0] * val[2][1] - val[0][1] * val[2][0]) / det;
// }

// static void		dots_fill_cb_res(float inv[4][4], t_vec4 const *p, t_vec3 *res)
// {
// 	res->x = (inv[0][0] + inv[1][0] + inv[2][0]) * p->x;
// 	res->y = (inv[0][1] + inv[1][1] + inv[2][1]) * p->y;
// 	res->z = (inv[0][2] + inv[1][2] + inv[2][2]) * p->z;
// }

void			dots_fill_cb(const t_vec4 *p, const t_mtx4 *c, t_vec3 *res)
{
	// t_mtx4	*inv;
	// float	det;

	// inv = mtx4_init(0);
	// det = dots_fill_cb_det(c->val);
	// dots_fill_cb_inv(c->val, inv->val, det);
	// dots_fill_cb_res(inv->val, p, res);
	t_vec3	*av = vec3_new(c->val[3][0], c->val[3][1], c->val[3][2]);
	t_vec3	*bv = vec3_new(c->val[3][0] + c->val[0][0], c->val[3][1] + c->val[0][1], c->val[3][2] + c->val[0][2]);
	t_vec3	*cv = vec3_new(c->val[3][0] + c->val[1][0], c->val[3][1] + c->val[1][1], c->val[3][2] + c->val[1][2]);

	float kx = (bv->y - av->y) * (cv->z - av->z) - (bv->z - av->z) * (cv->y - av->y);
	float ky = (bv->z - av->z) * (cv->x - av->x) - (bv->x - av->x) * (cv->z - av->z);
	float kz = (bv->y - av->y) * (cv->x - av->x) - (bv->x - av->x) * (cv->y - av->y);
	float d = -av->x * (bv->y - av->y) * (cv->z - av->z) -
		-av->x * (bv->z - av->z) * (cv->x - av->x) +
		-av->y * (bv->z - av->z) * (cv->x - av->x) -
		-av->y * (bv->x - av->x) * (cv->z - av->z) +
		-av->z * (bv->y - av->y) * (cv->x - av->x) -
		-av->z * (bv->x - av->x) * (cv->y - av->y);

	float l = (kx * p->x + ky * p->y + kz * p->z + d) / -(kx * kx + ky * ky + kz * kz);
	res->x = p->x + l * kx - av->x;
	res->y = p->y + l * ky - av->y;
	res->z = p->z + l * kz - av->z;
	// t_mtx4	*temp;
	// t_vec3	*l;
	// float	det;

	// l = vec3_new(-c->val[3][0] + p->x, -c->val[3][1] + p->y, -c->val[3][2] + p->z);
	// det = dots_fill_cb_det(c->val);
	// if (ft_fabs(det) < 0.00001f)
	// {
	// 	res = vec3_new(0, 0, 0);
	// 	return ;
	// }
	// temp = mtx4_copy(c);
	// dots_fill_cb_col(temp->val, l, 0);
	// res->x = dots_fill_cb_det(temp->val) / det;
	// free(temp);
	// temp = mtx4_copy(c);
	// dots_fill_cb_col(temp->val, l, 1);
	// res->y = dots_fill_cb_det(temp->val) / det;
	// free(temp);
	// temp = mtx4_copy(c);
	// dots_fill_cb_col(temp->val, l, 2);
	// res->z = dots_fill_cb_det(temp->val) / det;
	// free(temp);
}
