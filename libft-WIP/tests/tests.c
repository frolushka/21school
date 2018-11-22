/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:57:51 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/23 00:21:00 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

void	ft_assert_int(int a, int b, int *passed, int *failed)
{
	int temp = *passed;
	if (a != b)
		*failed += 1;
	else
		*passed += 1;
	printf("%s%d: %s", temp != *passed ? "" : "\n", *passed + *failed, temp != *passed ? "OK; " : "FAIL\t");
	if (temp != *passed)
		return;
	printf("assert %d == %d\n", a, b);
}

void	ft_assert_str(char *a, char *b, int *passed, int *failed)
{
	if (a == NULL && b == NULL)
	{
		*passed += 1;
		printf("%d: %s", *passed + *failed, "OK; ");
		return;
	}
	if (a == NULL || b == NULL)
	{
		*failed += 1;
		printf("\n%d: %s", *passed + *failed, "FAIL\t");
		goto FAIL;
	}
	int temp = *passed;
	int i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
		{
			*failed += 1;
			printf("%d: %s", *passed + *failed, "FAIL\t");
			goto FAIL;
		}
		i++;
	}
	if (a[i] || b[i])
		*failed += 1;
	else
		*passed += 1;
	printf("%s%d: %s", temp != *passed ? "" : "\n", *passed + *failed, temp != *passed ? "OK; " : "FAIL\t");
	if (temp != *passed)
		return;
	FAIL:
	printf("assert ");
	i = 0;
	while (a[i])
		printf("%d ", a[i++]);
	printf("(%s)", a);
	printf(" == ");
	i = 0;
	while (b[i])
		printf("%d ", b[i++]);
	printf("(%s)\n", b);
}

void	ft_assert_null(char *a, int *passed, int *failed)
{
	int temp = *passed;
	if (a != NULL)
		*failed += 1;
	else
		*passed += 1;
	printf("%s%d: %s", temp != *passed ? "" : "\n", *passed + *failed, temp != *passed ? "OK; " : "FAIL\t");
	if (temp != *passed)
		return;
	printf("assert %s == NULL\n", a == NULL ? "NULL" : "NOT NULL");
}
