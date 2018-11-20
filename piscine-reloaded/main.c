/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frolov <frolov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:26:45 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/20 11:43:10 by frolov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_print_alphabet(void);
//void	ft_print_numbers(void);
//void	ft_is_negative(int n);
//int		ft_recursive_factorial(int nb);

int		main(int argc, char **argv)
{
	argc--;
	argv++;
	ft_print_alphabet();
	//ft_print_numbers();
	//ft_is_negative(-24);
	//ft_is_negative(0);
	//ft_is_negative(1);
	//printf("%d\n", ft_recursive_factorial(atoi(argv[1])));
	return (0);
}
