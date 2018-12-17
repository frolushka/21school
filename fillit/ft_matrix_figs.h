/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_figs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:21:57 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/17 19:45:05 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_FIGS_H
# define FT_MATRIX_FIGS_H

# include "ft_dlist.h"
# include "ft_matrix.h"

int		ft_matrix_checkfg(t_matrix *m, int const r, int const c,
		int const fg);
int		ft_matrix_setfg(t_matrix **m, int const rc, int const fg,
		char const s);
void	ft_matrix_delfg(t_matrix **m, int const r, int const c, int const fg);

#endif
