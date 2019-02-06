/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:05:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 08:22:06 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_data(t_finfo const *f)
{
	if (!f || !(f->stat))
		return (-1);
	return (ctime(f->stat->st_mtimespec.tv_sec));
}

int	print_data(t_finfo const *f)
{
	char	*n;

	if (!(n = get_data(f)))
		return (-1);
	write(1, n, ft_strlen(n));
	return (0);
}
