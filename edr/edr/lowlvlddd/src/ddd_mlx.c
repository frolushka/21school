/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddd_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 04:31:54 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 01:02:05 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

t_mlx	*ddd_mlx_init(int width, int height, char *header)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(*res))))
		return (NULL);
	res->width = width;
	res->height = height;
	if (!(res->mlx = mlx_init()) ||
		!(res->win = mlx_new_window(res->mlx, width, height, header)) ||
		!(res->image = image_init(res, width, height)))
		return (NULL);
	return (res);
}
