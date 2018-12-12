/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:50:34 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/12 15:23:14 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVER_H
# define FT_SOLVER_H

# include "ft_dlist.h"
# include "ft_bmatrix.h"
# include "ft_bmtx_helper.h"
# include "ft_reader.h"
# include "ft_intarr.h"

int	get_square_size(int n);
int	set_lu_cell(int offset, t_bmatrix *ba, int *r, int *c);
int	get_fg_offset(t_dlist *fg);


#endif
