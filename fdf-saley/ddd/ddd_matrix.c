/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddd_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 02:45:31 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/22 08:45:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ddd.h"

t_mtx	*ddd_mtx_init(uint16_t const r, uint16_t const c)
{
	t_mtx	*res;

	if (!(res = (t_mtx *)malloc(sizeof(*res))))
		return (NULL);
	if (!(res->mtx = (float *)malloc(r * c * sizeof(int))))
	{
		free(res);
		return (NULL);
	}
	ft_bzero(res->mtx, r * c);
	res->r = r;
	res->c = c;
	return (res);
}