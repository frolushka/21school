/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmtx_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:33:44 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/12 08:27:38 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bmtx_helper.h"

/*
**	Функция проверяет, можно ли поставить фигуру fg в позицию (r, c) матрицы bm.
**	Возращаемые значения:	0, если фигура накладывается на уже имеющуюся
**							1, если можно
**							-1, если фигура не влезает в bm
*/

int		ft_bmatrix_checkfg(t_bmatrix *bm, int const r, int const c, t_dlist *fg)
{
	int	i;
	int	max_c;
	int max_r;
	int res;

	i = -1;
	max_c = -1;
	max_r = -1;
	res = 1;
	if (r < 0 || c < 0 || r >= bm->rows || c >= bm->cols)
		return (-1);
	while (++i <= 12)
		if (fg->value & (1 << i))
		{
			if (ft_bmatrix_get(bm, r + i / 4, c + i % 4) == 1)
				res = 0;
			if (i / 4 > max_r)
				max_r = i / 4;
			if (i % 4 > max_c)
				max_c = i % 4;
		}
	if (r + max_r >= bm->rows || c + max_c >= bm->cols)
		res = -1;
	return (res);
}

/*
**	Функция вставляет фигуру fg в позицию (r, c) матрицы bm,
**	проверив, может ли фигура находиться там.
**	Возвращаемые значения:	1, если вставка фигуры завершена корректно
**							0, если фигура накладывается(матрица остается без
**								изменений)
**							-1, если фигура не влезает(матрица остается без
**								изменений)
*/

int		ft_bmatrix_setfg(t_bmatrix **bm, int const r, int const c, t_dlist *fg)
{
	int	res;
	int	i;
	int size;

	i = -1;
	size = 4;
	if ((res = ft_bmatrix_checkfg(*bm, r, c, fg)) != 1)
		return (res);
	while (++i <= 12)
		if (fg->value & (1 << i))
		{
			size--;
			ft_bmatrix_set(bm, r + i / 4, c + i % 4, 1);
			if (size == 0)
				break ;
		}
	return (res);
}

/*
**	Функция очищает матрицу bm от фигуры fg, стоящей в позиции (r, c).
**	Функция не безопасна! Для ее использования необходимо точно знать, что
**	в матрице bm именно в позиции (r, c) находится именно фигура fg и никак
**	иначе. В противном случае, поведение неопределенно
*/

void	ft_bmatrix_delfg(t_bmatrix **bm, int const r, int const c, t_dlist *fg)
{
	int	i;
	int	size;

	i = -1;
	size = 4;
	while (++i <= 12)
		if (fg->value & (1 << i))
		{
			ft_bmatrix_set(bm, r + i / 4, c + i % 4, 0);
			size--;
			if (size == 0)
				return ;
		}
}
