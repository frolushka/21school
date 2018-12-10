/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:45:09 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/10 18:11:03 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	15 - horizontal stick
**	57 - horizontal mirror Г
**	113 - horizontal T up-down
**	99 - cube
**	51 - horizontal 4
**	225 - horizontal Г
**	195 - horizontal mirror 4
**  135 - horizontal Г up-down
**	71 - horizontal T
**	39 - horizontal mirrir Г up-down
**	1569 - vertical Г up-down
**	1073 - left T
**	561 - vertical mirror 4
**	3105 - vertical mirror Г up-down
**	2145 - vertical 4
**	1121 - right T
**	2115 - vertical mirror Г
**	1059 - vertical Г
**	33824 - vertical stick
*/

#include <stdio.h>
#include "ft_reader.h"

/*	Checks figure type.
**	Return: 0 if the figure is correct.
**			-1 if the figure is something strange.
*/
static int	check_figure(int fg)
{
	return (fg == 15 || fg == 57 || fg == 113 || fg == 99
			|| fg == 51 || fg == 225 || fg == 195 || fg == 135
			|| fg == 71 || fg == 39 || fg == 1569 || fg == 1073
			|| fg == 561 || fg == 3105 || fg == 2145 || fg == 1121
			|| fg == 1059 || fg == 33824);
}

static int	get_hash(t_barray *ba)
{
	int		res;
	int		fo;
	size_t	i;

	res = 0;
	fo = -1;
	i = -1;
	while (++i < ba->size * 8)
	{
		if (ft_ba_get(ba, i) == 1)
		{
			if (fo == -1)
				fo = i;
			else
				res += 1 << ((i + i / 4) - (fo + fo / 4));
		}
	}
	return (res);
}

/*	Tryes to read a single block of data (figure) from the file by the pattern.
**	Pattern means block of 4 lines that contain only 4 symbols '#' and '.' with
**	terminating '\n' at the end. Blocks must be separated by empty lines.
**	There is no empty line at the end of the file (last block).
**	Return: -1 if reading fails.
**			0 if reading OK.
*/
static int	read_figure(int fd, t_list **fig)
{
	int			i1;
	int			i2;
	char		*tmp;
	t_barray	*ba;
	int			sts;

	i1 = -1;
	if (!(ba = ft_ba_init(2)))
		return (-1);
	while (++i1 < 4)
	{
		if (get_next_line(fd, &tmp) < 1 || ft_strlen(tmp) != 4)
			return (-1);
		i2 = -1;
		while (++i2 < 4)
		{
			if (tmp[i2] != '#' && tmp[i2] != '.')
			{
				free(tmp);
				return (-1);
			}
			ft_ba_set(ba, i1 * 4 + i2, tmp[i2] == '#' ? 1 : 0);
		}
	}
	if (!check_figure(get_hash(ba)))
		return (-1);
	*fig = ft_lstnew("\0", (size_t)get_hash(ba));
	free(tmp);
	tmp = NULL;
	sts = get_next_line(fd, &tmp);
	if (sts == 1 && !(ft_strlen(tmp) == 1 && tmp[0] == '\n'))
		sts = -1;
	if (tmp == NULL)
		free(tmp);
	return (sts);
}

/*	Reads data from file descriptor [fd] and put results to var fgs.
**	Matching the right file pattern checked by function read_figure.
**	Return:	0 if function reached EOF of file.
**			-1 if an error occured.
*/
int			read_figures(int fd, t_list **fgs)
{
	t_list	*tmp;
	int		sts;

	/*  1 means OK but not EOF
	**	-1 means error
	*/
	while ((sts = read_figure(fd, &tmp)) != 0)
	{
		if (sts < 0)
		{
			close(fd);
			if (!tmp)
				free(tmp);
			ft_lstdels(fgs);
			return (-1);
		}
		ft_lstadd_back(fgs, tmp);
	}
	close(fd);
	return (0);
}