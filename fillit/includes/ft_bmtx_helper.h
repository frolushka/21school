/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmtx_helper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:23:29 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/12 12:49:47 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BMTX_HELPER_H
# define FT_BMTX_HELPER_H

# include "ft_dlist.h"
# include "ft_bmatrix.h"

int		ft_bmatrix_checkfg(t_bmatrix *bm, int const r, int const c,
		t_dlist *fg);
int		ft_bmatrix_setfg(t_bmatrix **bm, int const r, int const c, t_dlist *fg);
void	ft_bmatrix_delfg(t_bmatrix **bm, int const r, int const c, t_dlist *fg);

#endif
