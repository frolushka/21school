/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:53:37 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/26 01:25:21 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	size_t	i;
	size_t	srclen;

	cdst = (char *)dst;
	csrc = (char *)src;
	i = 0;
	srclen = ft_strlen(csrc);
	while (i < len && i < srclen)
	{
		cdst[i] = csrc[i];
		++i;
	}
	cdst[i] = '\0';
	return ((void *)cdst);
}
