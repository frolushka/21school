/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:50:34 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/13 12:13:10 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVER_H
# define FT_SOLVER_H

# include "ft_dlist.h"
# include "ft_matrix.h"
# include "ft_matrix_figs.h"
# include "ft_reader.h"

# define USAGE_MSG "usage: ./fillit source_file"

int		get_square_size(int const n);
int		find_place(t_dlist *fg, t_matrix **m, int ofs);
int		find_places(t_dlist *fg, t_matrix **m, int ofs);
int		solve(t_dlist *root);

#endif
