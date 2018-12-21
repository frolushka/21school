/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:49:43 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/20 21:10:41 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char const *f, ...)
{
	va_list		va;
	t_strlst	*res;
	int			res_len;

	if (!f)
		return (0);
	res = NULL;
	va_start(va, f);
	for (int i = 0; i < 4; i++)
		ft_strlst_add_new(&res, va_arg(va, char *));
	va_end(va);
	res_len = ft_strlst_print(res);
	ft_strlst_clear(&res);
	return (res_len);
}