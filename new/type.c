/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 06:56:12 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 07:35:54 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_type(t_finfo const *f)
{
	if (!f || !(f->dir) || !(f->dir->d_type))
		return (-1);
	return (f->dir->d_type);
}

void	set_colors_type(int const t)
{
	(t == DT_DIR ? set_colors("\x1b[34m", NULL) : 0);
	(t == DT_LNK ? set_colors("\x1b[35m", NULL) : 0);
	(t == DT_SOCK ? set_colors("\x1b[32m", NULL) : 0);
	(t == DT_FIFO ? set_colors("\x1b[33m", NULL) : 0);
}

int		print_type(t_finfo const *f)
{
	char	out[1];
	int		t;

	out[0] = '-';
	if ((t = get_type(f)) < 0)
		return (-1);
	(t == DT_BLK ? out[0] = 'b' : 0);
	(t == DT_CHR ? out[0] = 'c' : 0);
	(t == DT_DIR ? out[0] = 'd' : 0);
	(t == DT_LNK ? out[0] = 'l' : 0);
	(t == DT_SOCK ? out[0] = 's' : 0);
	(t == DT_FIFO ? out[0] = 'p' : 0);
	write(1, out, sizeof(out));
	return (0);
}


