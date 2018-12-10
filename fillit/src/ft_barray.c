/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_barray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:44:53 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/10 17:09:00 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_barray.h"

t_barray	*ft_ba_init(size_t size)
{
	t_barray	*res;
	size_t		i;

	if (!(res = (t_barray *)malloc(sizeof(t_barray *))))
		return (NULL);
	if (size == 0)
		res->array = NULL;
	else if (!(res->array = (unsigned char *)malloc(sizeof(size + 1))))
		return (NULL);
	res->size = size;
	i = -1;
	while (++i < size + 1)
		res->array[i] = '\0';
	return (res);
}

int		ft_ba_set(t_barray *ba, size_t pos, char val)
{
	size_t	ind;

	if (!ba || !(ba->array) || (val != 0 && val != 1))
		return (-1);
	ind = pos / 8;
	if (ind >= ba->size)
		return (-1);
	pos %= 8;
	if (val == 1)
		ba->array[ind] = ba->array[ind] | (1 << (7 - pos));
	else
		ba->array[ind] = ba->array[ind] & ((1 << (7 - pos)) ^ 0xFF);
	return (0);
}

int		ft_ba_get(t_barray *ba, size_t pos)
{
	size_t	ind;

	if (!ba || !(ba->array))
		return (-1);
	ind = pos / 8;
	if (ind >= ba->size)
		return (-1);
	pos %= 8;
	return ((ba->array[ind] & (1 << (7 - pos))) >> (7 - pos));
}

void	ft_ba_print(t_barray *ba)
{
	size_t	ind;

	if (!ba || !(ba->array))
		return ;
	ind = -1;
	printf("array:\n");
	while (++ind < ba->size * 8)
	{
		if (ind % 8 == 0)
			printf("  ");
		printf("%d ", (ft_ba_get(ba, ind)));
	}
	printf("\n");
}