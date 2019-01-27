/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 00:42:24 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 07:28:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

void	image_set_pixel(t_image *img, int const x, int const y, int const c)
{
	if (x < 0 || x >= SCREEN_X || y < 0 || y >= SCREEN_Y)
		return ;
	((int *)(img->ptr + ((x + y * SCREEN_X) * img->bpp)))[0] = c;
}

void	image_clear(t_image *img)
{
	ft_bzero(img->ptr, SCREEN_X * SCREEN_Y * img->bpp);
}

t_image	*image_init(t_mlx *mlx, int const x, int const y)
{
	t_image		*img;

	if (!(img = ft_memalloc(sizeof(*img))))
		return (NULL);
	if (!(img->image = mlx_new_image(mlx->mlx, x, y)))
	{
		free(img);
		return (NULL);
	}
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->str, &img->end);
	img->bpp /= 8;
	return (img);
}
