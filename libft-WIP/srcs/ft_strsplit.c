/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 01:35:13 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/26 21:21:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getstr(char *s, size_t n)
{
	char	*res;
	size_t	i;

	if (!(res = (char *)malloc(n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
		res[i++] = *s++;
	res[i] = '\0';
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	j;
	size_t 	i;
	size_t	wlen;

	if (s == NULL || !(res = (char **)malloc((ft_wordcnt(s, c) + 1) * sizeof(*res))))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		wlen = ft_wordlen(s, i, c);
		if (wlen != 0)
		{
			res[j++] = ft_getstr((char *)&s[i], wlen);
			i += wlen;
		}
		else
			++i;
	}
	res[j] = NULL;
	return (res);
}
