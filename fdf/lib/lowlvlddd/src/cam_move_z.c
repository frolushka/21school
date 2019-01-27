/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:26:15 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/22 22:48:20 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

void	cam_move_z(t_cam *cam, const float len)
{
	cam->cam->val[12] += cam->cam->val[8] * len;
	cam->cam->val[13] += cam->cam->val[9] * len;
	cam->cam->val[14] += cam->cam->val[10] * len;
}
