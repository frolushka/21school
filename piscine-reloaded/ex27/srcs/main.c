/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:48:58 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/20 16:53:40 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

int	main(int argc, char **argv)
{
	int	file;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			return (0);
		ft_display_file(file);
		close(file);
	}
	return (0);
}
