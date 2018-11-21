/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:48:58 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/21 18:49:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

void	ft_missing(void)
{
	char	*text;

	text = "File name missing.\n";
	ft_putstr(text);
}

void	ft_too_many(void)
{
	char	*text;

	text = "Too many arguments.\n";
	ft_putstr(text);
}

int		main(int argc, char **argv)
{
	int	file;

	if (argc == 1)
		ft_missing();
	else if (argc > 2)
		ft_too_many();
	else if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			return (0);
		ft_display_file(file);
		close(file);
	}
	return (0);
}
