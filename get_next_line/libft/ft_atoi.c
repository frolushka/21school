/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:14:24 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 21:43:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen_atoi(char const *str)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		++i;
	while (str[i] && ft_isdigit(str[i]))
	{
		++i;
		++res;
	}
	return (res);
}

int				ft_atoi(char const *str)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	if (ft_nbrlen_atoi(&str[i]) > 19)
		return (sign > 0 ? -1 : 0);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0') * sign;
	return (res);
}
