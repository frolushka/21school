/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:03:49 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/14 18:59:21 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lowlvlddd.h"

static int	check_valid(char *fn)
{
	int	x;
	int	y;
	int	fd;

	if ((fd = open(fn, O_RDONLY)) <= 0)
		return (0);
//todo
}

t_dots	*init_dots(char *fn)
{
	t_vector2	xy;
	int			fd;
	char		*tmp;
	char		**t;
	t_dots		*res;

	xy.y = 0;
	xy.x = 0;
	if ((fd = open(fn, O_RDONLY)) <= 0
			|| !(res = (t_dots *)malloc(sizeof(t_dots))))
		return (NULL);
	while (get_next_line(fd, &tmp) == 1)
	{
		y++;
		t = ft_strsplit(tmp, ' ');
		while (t[x])
		{
			if (ft_wrdscount(t[x], ",") == 1)
//todo
	}
	return (NULL);
}
