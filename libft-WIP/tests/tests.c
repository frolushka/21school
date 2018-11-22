/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:57:51 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/23 00:05:20 by sbednar          ###   ########.fr       */
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
	printf("%d: %s\t", *passed + *failed, temp != *passed ? "OK" : "FAIL");
	if (temp != *passed)
	{
		printf("\n");
		return;
	}
	printf("assert %d == %d\n", a, b);
}

void	ft_assert_str(char *a, char *b, int *passed, int *failed)
{
	if (a == NULL && b == NULL)
	{
		*passed += 1;
		printf("%d: %s\n", *passed + *failed, "OK");
		return;
	}
	if (a == NULL || b == NULL)
	{
		*failed += 1;
		printf("%d: %s\t", *passed + *failed, "FAIL");
		goto FAIL;
	}
	int temp = *passed;
	int i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
		{
			*failed += 1;
			printf("%d: %s\t", *passed + *failed, "FAIL");
			goto FAIL;
		}
		i++;
	}
	if (a[i] || b[i])
		*failed += 1;
	else
		*passed += 1;
	printf("%d: %s\t", *passed + *failed, temp != *passed ? "OK" : "FAIL");
	if (temp != *passed)
	{
		printf("\n");
		return;
	}
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
	printf("(%s)", b);
	printf("\n");
}

void	ft_assert_null(char *a, int *passed, int *failed)
{
	int temp = *passed;
	if (a != NULL)
		*failed += 1;
	else
		*passed += 1;
	printf("%d: %s\t", *passed + *failed, temp != *passed ? "OK" : "FAIL");
	if (temp != *passed)
	{
		printf("\n");
		return;
	}
	printf("assert %s == NULL\n", a == NULL ? "NULL" : "NOT NULL");
}
