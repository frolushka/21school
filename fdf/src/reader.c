/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 00:06:24 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/17 21:47:31 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

t_vec2	*check_valid(int fd)
{
	char	*l;
	t_vec2	*s;

	if (!(s = vec2_new(0, 0)))
		return (NULL);
	return (NULL);
}

t_vec4	**read_vecs(char *fn)
{
	char	*in;
	char	**tmp;
	int		st;
	int		fd;

	if ((fd = open(fn, O_RDONLY)) < 0)
		return (NULL);
	while ((st = get_next_line(fd, &in)) >= 0)
	{
		tmp = ft_strsplit(in, ' ');
		while (tmp)
			printf("%s ", (*tmp)++);
	}
	if (st < 0)
		return (NULL);
	return (NULL);
}