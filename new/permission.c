/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 07:31:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 07:40:34 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_permission(t_finfo const *f)
{
	if (!f || !(f->stat))
		return (-1);
	return (f->stat->st_mode);
}

int	print_permission(t_finfo const *f)
{
	int	p;

	if ((p = get_permission(f)) < 0)
		return (-1);
	write(1, ((p & S_IRUSR) ? "r" : "-"), 1);
	write(1, ((p & S_IWUSR) ? "w" : "-"), 1);
	write(1, ((p & S_IXUSR) ? "x" : "-"), 1);
	write(1, ((p & S_IRGRP) ? "r" : "-"), 1);
	write(1, ((p & S_IWGRP) ? "w" : "-"), 1);
	write(1, ((p & S_IXGRP) ? "x" : "-"), 1);
	write(1, ((p & S_IROTH) ? "r" : "-"), 1);
	write(1, ((p & S_IWOTH) ? "w" : "-"), 1);
	write(1, ((p & S_IXOTH) ? "x" : "-"), 1);
	return (0);
}
