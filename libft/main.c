/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:19:09 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/29 13:26:35 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "libft.h"

int main(void)
{
	for (long long i = LONG_MIN; i <= LONG_MAX; i++)
		if (ft_atoi(i) != atoi(i))
	return (0);
}