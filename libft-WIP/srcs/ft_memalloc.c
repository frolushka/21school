/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:07:01 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/25 23:09:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*res;
	size_t	i;

	if (!(res = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = '\0';
	return ((void *)res);
}
