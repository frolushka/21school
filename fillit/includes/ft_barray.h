/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_barray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:44:47 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/04 17:40:43 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPRESSOR_H
# define FT_COMPRESSOR_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct		s_barray
{
	unsigned char	*array;
	size_t			size;
}					t_barray;

t_barray			*ft_ba_init(size_t size);
int					ft_ba_set(t_barray *ba, size_t pos, char val);
int					ft_ba_get(t_barray *ba, size_t pos);

// DEBUG
void				ft_ba_print(t_barray *ba);

#endif