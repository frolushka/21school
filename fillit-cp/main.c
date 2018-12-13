/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:14:17 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/14 00:04:29 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "ft_dlist.h"
#include "ft_reader.h"
#include "ft_matrix.h"
#include "ft_matrix_figs.h"
#include "ft_solver.h"

int    main(int argc, char **argv)
{
	t_dlist	*fgs;
	int		fd;

	fgs = NULL;
	if (argc != 2)
	{
		ft_putendl(USAGE_MSG);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) <= 0
		|| read_figures(fd, &fgs) != 0
		|| solve(fgs) != 0)
		ft_putendl("error");
	if (fgs)
		free(fgs);
    return (0);
}
