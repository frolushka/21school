/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:04:27 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/20 16:27:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int res;

	res = 0;
	while (*str++)
		res++;
	return (res);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	if (!src || !(res = (char *)malloc(ft_strlen(src))))
		return (0);
	while (*src)
	{
		*res = *src++;
		res++;
	}
	return (res);
}
