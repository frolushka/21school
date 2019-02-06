/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_set_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:37:56 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/06 03:25:42 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	image_set_pixel(t_image *img, int const x, int const y, int const c)
{
	if (x < -img->x / 2.0f || x > img->x / 2.0f || y < -img->y / 2.0f || y > img->y / 2.0f)
		return ;
	((int *)(img->ptr + (int)((x + img->x / 2.0f) + (y + img->y / 2.0f) * img->x) * img->bpp))[0] = c;
}
