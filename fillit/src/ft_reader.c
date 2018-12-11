/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:45:09 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/11 01:54:14 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	14 - horizontal stick
**	56 - horizontal mirror Г
**	112 - horizontal T up-down
**	98 - cube
**	50 - horizontal 4
**	224 - horizontal Г
**	194 - horizontal mirror 4
**  134 - horizontal Г up-down
**	70 - horizontal T
**	38 - horizontal mirrir Г up-down
**	1568 - vertical Г up-down
**	1072 - left T
**	560 - vertical mirror 4
**	3104 - vertical mirror Г up-down
**	2144 - vertical 4
**	1120 - right T
**	2114 - vertical mirror Г
**	1058 - vertical Г
**	33824 - vertical stick
*/

#include "ft_reader.h"

/*	Проверяет тип фигуры (наличие ее хэша в списке корректных фигур).
**	Возвращаемое значение:	0, если фигура некорректна.
**						  	1, если фигура корректна.
*/
static int	check_figure(int fg)
{
	return (fg == 14 || fg == 56 || fg == 112 || fg == 98
			|| fg == 50 || fg == 224 || fg == 194 || fg == 134
			|| fg == 70 || fg == 38 || fg == 1568 || fg == 1072
			|| fg == 560 || fg == 3104 || fg == 2144 || fg == 1120
			|| fg == 1058 || fg == 33824);
}

/*	Считает хэш фигуры на основе строки str. Хэш высчитывается по формуле,
**	которую аккуратно вывел Мася потными прогерскими вечерами :3
**	Возвращаемое значение:	хэш фигуры.
**
*/
static int	get_hash(char const *str)
{
	int	res;
	int	fo;
	int	i;
	int	len;

	res = 0;
	fo = -1;
	i = -1;
	len = (int)ft_strlen(str);
	while (++i < len)
	{
		if (str[i] == '#')
		{
			if (fo == -1)
				fo = i;
			else
				res += 1 << ((i + i / 4) - (fo + fo / 4));
		}
	}
	return (res);
}

/*	Пытается считать фигуру из файла, заданную по шаблону.
**	Шаблон представляет из себя фигуру размером 4 на 4.
**	В случае нарушения шаблона выдает ошибку.
**	Возвращаемое значение:	1, если чтение прошло без ошибок.
**							0, если возникли ошибки.
*/
static int	read_block(int fd, char **block)
{
	int		i1;
	int		i2;
	char	*tmp;

	i1 = -1;
	*block = (char *)ft_memalloc(17);
	while (++i1 < 4)
	{
		if (get_next_line(fd, &tmp) < 1 || ft_strlen(tmp) != 4)
			return (0);
		i2 = -1;
		while (++i2 < 4)
		{
			if (tmp[i2] != '#' && tmp[i2] != '.')
			{
				free(tmp);
				return (0);
			}
		}
		ft_strcat(*block, tmp);
	}
	return (1);
}

/*	Создает новую вершину t_dlist на основе считанного блока из read_block,
**	после чего записывает ее по адресу fig. Если после блока в файле не стоит
**	символ '\n' или EOF, выдает ошибку.
**	Возвращаемое значение:	-1, если произошла ошибка чтения.
**							0, если чтение прошло без ошибок и EOF.
**							1, если чтение прошло без ошибок и не EOF.
*/
static int	read_figure(int fd, t_dlist **fig)
{
	int		hash;
	int		sts;
	char	*block;

	if (!read_block(fd, &block))
		return (-1);
	hash = get_hash(block);
	free(block);
	if (!check_figure(hash))
		return (-1);
	*fig = ft_dlst_new(hash);
	sts = get_next_line(fd, &block);
	if (sts == 1 && *block)
		sts = -1;
	if (sts != 0 && block)
		free(block);
	return (sts);
}

/*	Считывает список фигур из файла, заданного дескриптором fd.
**	Возвращаемое значение:	0, если чтение прошло без ошибок.
**							-1, если во время чтения файла возникли ошибки.
*/
int			read_figures(int fd, t_dlist **fgs)
{
	t_dlist	*tmp;
	int		sts;
	int		size;

	size = 0;
	while ((sts = read_figure(fd, &tmp)) != 0)
	{
		if (sts < 0 || ++size > 26)
		{
			close(fd);
			if (!tmp)
				free(tmp);
			ft_dlst_clear(fgs);
			return (-1);
		}
		ft_dlst_pushback(fgs, tmp);
	}
	close(fd);
	return (0);
}