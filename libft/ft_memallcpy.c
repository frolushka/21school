/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:15:45 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:18:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memallcpy(void const *src, size_t len)
{
	char	*res;

	if (!(res = malloc(len)))
		return (NULL);
	res = ft_strncpy(res, (char *)src, len);
	return ((void *)res);
}
