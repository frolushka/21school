/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:09:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 22:15:51 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char **argv)
{
	int fd = open("mars.fdf", O_RDONLY);
	char *line = NULL;
	char **tmp;
	while (get_next_line(fd, &line) != 0)
	{
		tmp = ft_strsplit(line, ' ');
		ft_strdel(&line);
		ft_strsdel(&tmp);
	}
	return (0);
}
