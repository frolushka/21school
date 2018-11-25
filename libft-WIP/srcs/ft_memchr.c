/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:11:14 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/23 15:17:15 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	*ft_memchr(void const *s, int c, size_t n)
{
	char	*cs;
	size_t	i;

	cs = (char *)s;
	i = -1;
	while (++i < n)
	{
		if ((unsigned char)cs[i] == (unsigned char)c)
			return ((void *)(&cs[i]));
	}
	return (NULL);
}
