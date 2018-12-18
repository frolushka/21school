/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:49:43 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/17 18:08:51 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *f, ...)
{
	va_list	va;
	t_list	*toks;
	char	*res;

	if (!f || !(toks = ft_toks_get(f)))
		return (0);
	va_start(va, f);
	res = ft_toks_parse(f, toks);
	va_end(va);
	ft_lstdels(&toks);
	return (ft_strlen(res));
}