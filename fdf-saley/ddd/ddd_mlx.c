/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddd_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 04:31:54 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/22 04:39:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ddd.h"

t_mlx	*ddd_mlx_init(int width, int height, char *header)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(*res))))
		return (NULL);
	res->width = width;
	res->height = height;
	if (!(res->mlx = mlx_init()) ||
		!(res->win = mlx_new_window(res->mlx, width, height, header)))
		return (NULL);
	return (res);
}