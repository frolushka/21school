/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:26:15 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 06:07:47 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

void	cam_move_y(t_cam *cam, const float len)
{
	cam->cam->val[12] += cam->cam->val[4] * len;
	cam->cam->val[13] += cam->cam->val[5] * len;
	cam->cam->val[14] += cam->cam->val[6] * len;
}
