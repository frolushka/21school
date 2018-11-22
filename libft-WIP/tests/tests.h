/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:56:33 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/22 23:51:53 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

void	ft_assert_int(int a, int b, int *passed, int *failed);
void	ft_assert_str(char *a, char *b, int *passed, int *failed);
void	ft_assert_ptr(char *a, char *b, int *passed, int *failed);
void	ft_assert_null(char *a, int *passed, int *failed);

# include "tests.c"

#endif
