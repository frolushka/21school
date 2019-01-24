/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:26:15 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 06:04:23 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

void	cam_move_x(t_cam *cam, const float len)
{
	cam->cam->val[12] += cam->cam->val[0] * len;
	cam->cam->val[13] += cam->cam->val[1] * len;
	cam->cam->val[14] += cam->cam->val[2] * len;
}
