/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:08:49 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/01 23:37:39 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	print_tlist(t_list const *root)
{
	if (!root)
		return ;
	printf("node: %s %zu\n", root->content ? "NON NULL" : "NULL", root->content_size);
	print_tlist(root->next);
}

int main(void)
{
	int fd;
	char	*line;
	// char buf[33];
	// buf[32] = '\0';

	line = NULL;
    fd = open("42.txt", O_RDONLY);
	// fd = 42;
	// read(fd, buf, BUFF_SIZE + 1);
	// printf("%s\n", buf);
	int check = get_next_line(fd, &line);
	while (check == 1)
		printf("%s\n", line);
	// static t_list	*root;

	// get_current_node(1, &root);
	// get_current_node(2, &root);
	// get_current_node(3, &root);
	// get_current_node(1, &root);
	// get_current_node(5, &root);
	// print_tlist(root);
	return (0);
}
