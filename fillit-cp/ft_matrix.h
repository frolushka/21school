/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:16:12 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/13 01:29:22 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include <stdlib.h>
# include <string.h>
# include "libft.h"

typedef struct	s_matrix
{
	char		*matrix;
	int			cols;
	int			rows;
}				t_matrix;

t_matrix		*ft_matrix_init(int rs, int cs);
char			ft_matrix_get(t_matrix const *m, int const r, int const c);
int				ft_matrix_set(t_matrix **m, int const r, int const c,
								char const val);
void			ft_matrix_delete(t_matrix **m);
void			ft_matrix_print(t_matrix const *m);

#endif
