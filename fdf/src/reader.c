/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 00:06:24 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/16 00:13:44 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	*check_valid(int fd)
{
	char	*l;
	t_vec2	*s;

	if (!(s = vec2_new(0, 0)))
		return (NULL);
	while (get_next_line())
	{

	}
	return (NULL);
}

t_vec4	**read_vecs(char *fn)
{
	char	*in;
	int		fd;

	if ((fd = open()
}