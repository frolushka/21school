/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:56:15 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/22 23:37:06 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char	*csrc;
	char	*cdst;
	int		i;

	csrc = (char *)src;
	cdst = (char *)dst;
	i = 0;

	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return ((void *)cdst);
}
