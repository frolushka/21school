/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 21:00:55 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/28 21:19:35 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void inline	put_char(t_info *i, char c)
{
	i->len += write(i->fd, &c, 1);
}

static void			put_wchar(t_info *i, char c)
{
	if (c <= 0x7F)
		put_char(i, c);
	else if (c <= 0x7FF)
	{
		put_char(i, (c >> 6) + 0xC0);
		put_char(i, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_char(i, ((c >> 12) + 0xE0));
		put_char(i, ((c >> 6) & 0x3F) + 0x80);
		put_char(i, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_char(i, (c >> 18) + 0xF0);
		put_char(i, ((c >> 12) & 0x3F) + 0x80);
		put_char(i, ((c >> 6) & 0x3F) + 0x80);
		put_char(i, (c & 0x3F) + 0x80);
	}
	++i->len;
}

void				print_wchar(t_info *i, wchar_t wc)
{
	if (i->cfs & FLAG_minus)
	{
		put_wchar(i, wc);
		while (i->wid-- > 1)
			i->len += write(i->fd, " ", 1);
	}
	else
	{
		while (i->wid-- > 1)
			i->len += write(i->fd, (i->cfs & FLAG_zero ? "0" : " "), 1);
		put_wchar(i, wc);
	}
	++i->ind;
}