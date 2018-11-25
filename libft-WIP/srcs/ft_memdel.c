/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:09:47 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/26 01:32:47 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	char	**cap;

	if (ap == NULL)
		return ;
	cap = (char **)ap;
	free(*cap);
	*cap = NULL;
	ap = (void **)cap;
}
