/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:15:03 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/28 21:18:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_wstring_len(wchar_t *ws)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (ws[++i])
	{
		if (ws[i] <= 0x7F)
			++res;
		else if (ws[i] <= 0x7FF)
			res += 2;
		else if (ws[i] <= 0xFFFF)
			res += 3;
		else if (ws[i] <= 0x10FFFF)
			res += 4;
	}
	return (res);
}

void		print_wstring(t_info *i, wchar_t *ws)
{

}