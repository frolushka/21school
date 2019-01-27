/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:55:35 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 05:48:25 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rot_around_y(float a, const t_mtx4 *src, t_mtx4 *dst)
{
	t_vec3	*axis;

	axis = vec3_new(src->val[4], src->val[5], src->val[6]);
	mtx4_rot_axis(axis, a, src, dst);
	free(axis);
}

static void	rot_around_x(float a, const t_mtx4 *src, t_mtx4 *dst)
{
	t_vec3	*axis;

	axis = vec3_new(src->val[0], src->val[1], src->val[2]);
	mtx4_rot_axis(axis, a, src, dst);
	free(axis);
}

int	hook_mouse_move(int x, int y, t_mouse *mouse)
{
	int		dx;
	int		dy;
	t_mtx4	*temp;

	mouse->prev_x = mouse->x;
	mouse->prev_y = mouse->y;
	mouse->y = y;
	mouse->x = x;
	temp = mtx4_cpy((*(mouse->cam))->cam);
	dx = mouse->x - mouse->prev_x;
	dy = mouse->y - mouse->prev_y;
	if (ABS(dx) > mouse->error && ABS(dx) < 100)
		rot_around_y((float)dx * mouse->sence, temp, (*(mouse->cam))->cam);
	if (ABS(dy) > mouse->error && ABS(dy) < 100)
		rot_around_x((float)dy * mouse->sence, temp, (*(mouse->cam))->cam);
	if (ABS(dx) > mouse->error || ABS(dy) > mouse->error)
		redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	free(temp);
	return (0);
}
