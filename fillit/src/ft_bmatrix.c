/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:45:59 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/12 08:26:47 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bmatrix.h"

t_bmatrix		*ft_bmatrix_init(int rs, int cs)
{
	t_bmatrix	*res;

	if (rs <= 0 || cs <= 0 || !(res = (t_bmatrix *)malloc(sizeof(res))))
		return (NULL);
	if (!(res->matrix = ft_memalloc(rs * cs / 8 + 1)))
	{
		ft_bmatrix_delete(&res);
		return (NULL);
	}
	res->rows = rs;
	res->cols = cs;
	return (res);
}

int				ft_bmatrix_get(t_bmatrix const *bm, int const r, int const c)
{
	int	rs;
	int	cs;

	if (!bm)
		return (-1);
	rs = bm->rows;
	cs = bm->cols;
	if (r >= rs || c >= cs)
		return (-1);
	return ((bm->matrix[(r * cs + c) / 8] &
		(1 << ((r * cs + c - 1) % 8))) != 0 ? 1 : 0);
}

int				ft_bmatrix_set(t_bmatrix **bm, int const r, int const c,
								int const val)
{
	int	rs;
	int	cs;

	if (!bm || !*bm)
		return (-1);
	rs = (*bm)->rows;
	cs = (*bm)->cols;
	if (r >= rs || c >= cs || !(val == 0 || val == 1))
		return (-1);
	if (val == 1)
		(*bm)->matrix[(r * cs + c) / 8] |= (1 << ((r * cs + c - 1) % 8));
	else
		(*bm)->matrix[(r * cs + c) / 8] &= ~(1 << ((r * cs + c - 1) % 8));
	return (0);
}

void			ft_bmatrix_delete(t_bmatrix **bm)
{
	if (!bm || !*bm)
		return ;
	free((*bm)->matrix);
	free(*bm);
	*bm = NULL;
}

void			ft_bmatrix_print(t_bmatrix const *bm)
{
	int	i;
	int	rs;
	int	cs;

	if (!bm)
		return ;
	rs = bm->rows;
	cs = bm->cols;
	i = -1;
	printf("matrix:\n");
	while (++i < rs * cs)
	{
		printf("%d ", ft_bmatrix_get(bm, i / cs, i % cs));
		if (i % cs == cs - 1)
			printf("\n");
	}
}
