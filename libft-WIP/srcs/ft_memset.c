/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:58:02 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/22 23:37:11 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	int		i;

	p = (char *)b;
	i = 0;
	while (i < len)
		p[i++] = (unsigned char)c;
	return ((void *)p);
}
