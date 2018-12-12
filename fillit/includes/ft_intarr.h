/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:58:03 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/12 11:27:12 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTARR_H
# define FT_INTARR_H

# include <stdlib.h>

int		*ft_arr_init(unsigned int n);
void	ft_arr_swp_el(int *a, unsigned int e1, unsigned int e2);
int		ft_next_sequence(int *a, unsigned int n);
void	ft_print_arr(int *a, unsigned int n);
void	ft_arrdel(int **a);

#endif
