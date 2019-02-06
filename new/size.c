/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:03:01 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 08:04:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_size(t_finfo const *f)
{
	if (!f || !(f->stat))
		return (-1);
	return (f->stat->st_size);
}

int	print_size(t_finfo const *f)
{
	char	*n;
	int		l;

	if ((l = get_size(f)) < 0 || !(n = ft_itoa(l)))
		return (-1);
	write(1, n, ft_strlen(n));
	return (0);
}
