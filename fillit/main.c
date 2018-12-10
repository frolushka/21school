/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:14:17 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/10 18:24:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "ft_reader.h"
#include "libft.h"
#include "ft_util.h"

int	main(int argc, char **argv)
{
	t_list	*fgs;
	int		fd;

	fgs = NULL;
	if (argc != 2)
	{
		write(1, USAGE_MSG, sizeof(USAGE_MSG));
		exit(0);
	}
	if (!(fd = open(argv[1], O_RDONLY))
		|| read_figures(fd, &fgs) != 0)
		write(1, "error\n", 6);
	else
		write(1, "ok\n", 3);
	t_list *cur = fgs;
	while (cur)
	{
		printf("%zu\n", cur->content_size);
		cur = cur->next;
	}
	return (0);
}
