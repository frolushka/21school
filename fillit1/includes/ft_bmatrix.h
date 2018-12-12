/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmatrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:45:42 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/12 12:47:21 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BMATRIX_H
# define FT_BMATRIX_H

# include <stdio.h>
# include <string.h>
# include "libft.h"

typedef struct	s_bmatrix
{
	char		*matrix;
	int			cols;
	int			rows;
}				t_bmatrix;

t_bmatrix		*ft_bmatrix_init(int rs, int cs);
int				ft_bmatrix_get(t_bmatrix const *bm, int const r, int const c);
int				ft_bmatrix_set(t_bmatrix **bm, int const r, int const c,
								int const val);
void			ft_bmatrix_delete(t_bmatrix **bm);
void			ft_bmatrix_print(t_bmatrix const *bm);

#endif
