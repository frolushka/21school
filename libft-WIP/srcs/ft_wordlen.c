/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:37:14 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/26 20:39:15 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(char const *s, size_t pos, char del)
{
	size_t	res;

	res = 0;
	while (s[pos] && s[pos] != del)
	{
		++res;
		++pos;
	}
	return (res);
}
