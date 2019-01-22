/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 20:59:33 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/22 03:47:31 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	parse_flags(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == '-')
		++i;
	while (str[i])
	{
		if (str[i] == 'l')
			res |= FLAG_l;
		else if (str[i] == 'R')
			res |= FLAG_R;
		else if (str[i] == 'a')
			res |= FLAG_a;
		else if (str[i] == 'r')
			res |= FLAG_r;
		else if (str[i] == 't')
			res |= FLAG_t;
		else
			return (-i);
		++i;
	}
	return (res);
}

static void inline	print_wrf(char const c)
{
	write(1, FT_LS, sizeof(FT_LS));
	write(1, ILLOPT, sizeof(ILLOPT));
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, USAGE, sizeof(USAGE));
}

int			main(int argc, char **argv)
{
	int		flags;
	size_t	i;

	if (argc > 1)
	{
		i = 0;
		if ((flags = (argv[1][0] == '-' ? parse_flags(argv[++i]) : 0)) < 0)
		{
			print_wrf(argv[1][-flags]);
			return (0);
		}
		(argc - (flags == 0 ? 1 : 2) > 1 ? flags |= FLAG_mult : 0);
		if (i == argc - 1)
			ft_ls(".", flags);
		while (++i < argc)
			ft_ls(argv[i], flags);
	}
	else
		ft_ls(".", 0);
	return (0);
}