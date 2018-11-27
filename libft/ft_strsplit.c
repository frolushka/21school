/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 01:35:13 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 19:29:35 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	wrd;
	char	**s;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	wrd = ft_count_words(str, c);
	if (!(s = (char **)malloc(sizeof(s) * (ft_count_words(str, c) + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		++i;
	while (j < wrd && str[i])
	{
		s[j] = ft_word(str, c, &i);
		++j;
	}
	s[j] = NULL;
	return (s);
}
