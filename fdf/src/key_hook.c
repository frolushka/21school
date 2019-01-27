/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:44:24 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/24 21:11:45 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hook_w(t_mouse *mouse)
{
	cam_move_z(*(mouse->cam), 1);
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	return (0);
}

static int	hook_s(t_mouse *mouse)
{
	cam_move_z(*(mouse->cam), -1);
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	return (0);
}

static int	hook_q(t_mouse *mouse)
{
	cam_move_y(*(mouse->cam), -1);
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	return (0);
}

static int	hook_e(t_mouse *mouse)
{
	cam_move_y(*(mouse->cam), 1);
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	return (0);
}

static int	hook_d(t_mouse *mouse)
{
	cam_move_x(*(mouse->cam), 1);
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	return (0);
}

static int	hook_a(t_mouse *mouse)
{
	cam_move_x(*(mouse->cam), -1);
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	return (0);
}

static int	hook_f(t_mouse *mouse)
{
	if ((*(mouse->cam))->mode == CAM_ISO)
		(*(mouse->cam))->mode = CAM_PERSP;
	else
		(*(mouse->cam))->mode = CAM_ISO;
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	return (0);
}

static int	hook_esc(void)
{
	//free all
	exit(0);
	return (0);
}

int	hook_rot_debug(int key, t_mouse *mouse)
{
	float		dx = 0;
	float		dy = 0;
	t_mtx4	*temp;

	temp = mtx4_cpy((*(mouse->cam))->cam);
	if (key == 126)
		dy = 1.0f;
	if (key == 125)
		dy = -1.0f;
	if (key == 123)
		dx = -1.0f;
	if (key == 124)
		dx = 1.0f;
	if (dx != 0)
		mtx4_rot_y(dx, temp, (*(mouse->cam))->cam);
	else
		mtx4_rot_x(dy, temp, (*(mouse->cam))->cam);
	//if (ABS(dx) > mouse->error || ABS(dy) > mouse->error)
	redraw(mouse->mlx, mouse->dots, *(mouse->cam));
	// mtx4_print((*(mouse->cam))->cam);
	free(temp);
	return (0);
}

int			key_hook(const int key, t_mouse *mouse)
{
	if (key == 13)
		return (hook_w(mouse));
	else if (key == 53)
		return (hook_esc());
	else if (key == 1)
		return (hook_s(mouse));
	else if (key == 3)
		return (hook_f(mouse));
	else if (key == 0)
		return (hook_a(mouse));
	else if (key == 2)
		return (hook_d(mouse));
	else if (key == 12)
		return (hook_q(mouse));
	else if (key == 14)
		return (hook_e(mouse));
	else
		return (hook_rot_debug(key, mouse));
	return (0);
}
