/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:30:44 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/26 10:32:39 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int nbr)
{
	size_t	res;

	res = 1;
	if (nbr < 0)
		res++;
	while (nbr /= 10)
		res++;
	return (res);
}
