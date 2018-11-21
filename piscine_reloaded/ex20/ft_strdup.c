/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:04:27 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/21 18:46:03 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*res;

	len = 0;
	while (src[len])
		len++;
	res = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		res[i] = src[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}
