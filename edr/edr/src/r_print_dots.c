/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:38:06 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 22:38:22 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			print_dots(t_dots *res)
{
	int	i;
	int	j;

	i = -1;
	while (++i < res->yc)
	{
		j = -1;
		while (++j < res->xc)
		{
			printf("(%.3f,%.3f,%.3f,%.3f)\t", res->local[i * res->xc + j]->x, res->local[i * res->xc + j]->y, res->local[i * res->xc + j]->z, res->local[i * res->xc + j]->w);
		}
		printf("\n");
	}
	return (0);
}
