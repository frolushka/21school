/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:21:38 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/26 20:27:42 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcnt(char const *s, char del)
{
	size_t	res;
	size_t	i;
	int		is_word;

	res = 0;
	i = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != del && !is_word)
			is_word = 1;
		else if (s[i] == del && is_word)
		{
			is_word = 0;
			++res;
		}
		++i;
	}
	return (res);
}
