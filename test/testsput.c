/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:29:26 by amerlon-          #+#    #+#             */
/*   Updated: 2018/11/29 19:40:07 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd = open("../test/test2_received_fd", O_RDWR);
	ft_putchar('a');
	ft_putchar('s');
	ft_putchar('\n');

	ft_putchar_fd('a', fd);
	ft_putchar_fd('s', fd);
	ft_putchar_fd('\n', fd);

	ft_putstr("qweasd\n");
	ft_putstr_fd("qweasd\n", fd);

	ft_putendl("qweasd");
	ft_putendl_fd("qweasd", fd);

	ft_putnbr(123);
	ft_putnbr(-123);
	ft_putnbr(-2147483648);
	ft_putnbr(2147483647);
	ft_putchar('\n');

	ft_putnbr_fd(123, fd);
	ft_putnbr_fd(-123, fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);

	ft_putstr("Check for crashes\n");
	ft_putstr_fd("Check for crashes\n", fd);
	ft_putstr(NULL);
	ft_putstr_fd(NULL, fd);
	ft_putendl(NULL);
	ft_putendl_fd(NULL, fd);

	ft_putstr("OK\n");
	ft_putstr_fd("OK\n", fd);
	close(fd);
}
