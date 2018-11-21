/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:38:41 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/21 18:48:07 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
		return (NULL);
	if (!(res = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	i = -1;
	while (min + ++i < max)
		res[i] = min + i;
	return (res);
}
