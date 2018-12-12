/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:07:24 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/12 11:47:00 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_intarr.h"
#include <stdio.h>

/*
**	Создает и возвращает новый массив длиной n со значениями в диапозоне [0, n)
**	в возрастающем порядке. В случае, если не удалось выделить память - NULL
*/

int		*ft_arr_init(unsigned int n)
{
	int	i;
	int	*res;

	i = -1;
	if (!(res = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (++i < (int)n)
		res[i] = i;
	return (res);
}

/*
**	Меняет елементы е1 и е2 массива a местами
*/

void	ft_arr_swp_el(int *a, unsigned int e1, unsigned int e2)
{
	int	tmp;

	tmp = a[e1];
	a[e1] = a[e2];
	a[e2] = tmp;
}

/*
**	Переставляет элементы массива a длиной n таким образом, чтобы получить
**	следующую последовательность его значение в лексикографическом порядке.
**	Возвращаемые значения:	0 - посл-ть перед вызовом функции финальная и
**								петестановку осуществить невозможно
**							1 - перестановка прошла успешно
*/

int		ft_next_sequence(int *a, unsigned int n)
{
	int	i;
	int	j;
	int	k;
	int	r;

	j = (int)n - 2;
	k = (int)n - 1;
	r = k;
	while (j != -1 && a[j] >= a[j + 1])
		j--;
	i = j + 1;
	if (j == -1)
		return (0);
	while (a[j] >= a[k])
		k--;
	ft_arr_swp_el(a, j, k);
	while (i < r)
		ft_arr_swp_el(a, i++, r--);
	return (1);
}

void	ft_arrdel(int **a)
{
	free(*a);
	*a = NULL;
}

/*
**	*****************ДЕБАГ******************
**			выводит массив а длинной н
**	*****ПОЧИСТИТЬ ИБО ФОРБИДДЕН ФУНКШОН****
*/

void	ft_print_arr(int *a, unsigned int n)
{
	for (int i = 0; i < (int)n; i++)
	   printf("%d, ", a[i]);
	printf("\n");
}
