/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:35:54 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/13 02:46:27 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solver.h"

/*
**	Функция на вход получает кол-во фигур и возвращает сторону минимально
**	возможного квадрата, теоритически вмещающего в себя данные фигуры.
**	Возвращаемые значения:	возвращает сторону квадрата.
*/

int		get_square_size(int const n)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt * sqrt < 4 * n)
		++sqrt;
	return (sqrt);
}

int		find_place(t_dlist *fg, t_matrix **m, int ofs)
{
	int	i;
	int	rs;
	int	cs;

	i = ofs;
	rs = (*m)->rows;
	cs = (*m)->cols;
	while (++i < rs * cs)
	{
		if (ft_matrix_checkfg(*m, i / cs, i % cs, fg->value) == 1)
			return (i);
	}
	return (-1);
}

int		find_places(t_dlist *fg, t_matrix **m, int ofs)
{
	int	i;
	int	rs;
	int	cs;

	if (!fg)
		return (0);
	i = -1;
	rs = (*m)->rows;
	cs = (*m)->cols;
	while ((i = find_place(fg, m, i)) != -1)
	{
		ft_matrix_setfg(m, i / cs, i % cs, fg->value, 'A' + ofs);
		if (find_places(fg->next, m, ofs + 1) == 0)
			return (0);
		ft_matrix_delfg(m, i / cs, i % cs, fg->value);
	}
	return (-1);
}

int		solve(t_dlist *root)
{
	t_matrix	*m;
	int			min_size;

	if (!root)
		return (-1);
	min_size = get_square_size(ft_dlst_size(root));
	m = ft_matrix_init(min_size, min_size);
	while (find_places(root, &m, 0) < 0)
	{
		ft_matrix_delete(&m);
		min_size++;
		m = ft_matrix_init(min_size, min_size);
	}
	ft_matrix_print(m);
	return (0);
}