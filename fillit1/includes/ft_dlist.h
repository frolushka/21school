/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 00:32:48 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/11 01:01:58 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

#include <stdlib.h>
#include "string.h"

typedef struct		s_dlist
{
	struct s_dlist	*next;
	int				value;
}					t_dlist;

t_dlist				*ft_dlst_new(int const val);
int					ft_dlst_pushback(t_dlist **root, t_dlist *node);
int					ft_dlst_clear(t_dlist **root);
int					ft_dlst_size(t_dlist **root);

#endif