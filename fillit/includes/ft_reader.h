/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:18:04 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/10 16:46:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READER_H
# define FT_READER_H

#include "ft_barray.h"
#include "get_next_line.h"
#include "libft.h"

int	read_figures(int fd, t_list **fgs);

#endif