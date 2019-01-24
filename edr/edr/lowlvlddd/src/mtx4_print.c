/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:06:38 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 01:04:56 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"
#include <stdio.h>

void	mtx4_print(const t_mtx4 *src)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			printf("%f(i = %d, j = %d)\t", src->val[i * 4 + j], i, j);
		}
		printf("\n");
		j = -1;
	}
	printf("\n");
}
