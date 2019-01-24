/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:39:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/23 01:19:15 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int inline	lerp(char const *it)
{
	int	res;
	int i;

	i = ft_atoi(it);
	if (i < -20)
		res = 0xFF0000;
	else if (i >= -20 && i < 20)
		res = color_lerp(0xFF0000, 0xFFFFFF, (float)(20 + i) / 40);
	else
		res = 0xFFFFFF;
	return (res);
}

int					get_color(char const *it)
{
	int	i;
	int	k;
	int	res;

	i = 0;
	res = 0;
	while (it[i] && (it[i] == '-' || ft_isdigit(it[i])))
		++i;
	if (it[i] == ',')
	{
		i += 3;
		k = -1;
		while (++k < 6)
		{
			res += it[i + k] > '9' ? it[i + k] - 'A' + 10 : it[i + k] - '0';
			res = res << 4;
		}
	}
	else
		res = lerp(it);
	return (res);
}

int					free_all(char **line, char ***tmp, int fd)
{
	if (line)
		ft_strdel(line);
	if (tmp)
		ft_strsdel(tmp);
	if (fd > 0)
		close(fd);
	return (0);
}
