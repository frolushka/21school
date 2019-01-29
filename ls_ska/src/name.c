/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 08:06:13 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/29 08:43:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_name(t_finf const *f)
{
	if (!f || !(f->dir))
		return (NULL);
	return (f->dir->d_name);
}

int	print_name(t_finf const *f)
{
	char	*n;

	if (!(n = get_name(f)))
		return (-1);
	write(1, n, ft_strlen(n));
	return (0);
}
