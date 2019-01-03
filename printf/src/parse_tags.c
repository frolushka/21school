/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 03:01:08 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/02 03:02:49 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	set_tag(char const *fmt, t_info *i)
// {
// 	int	ind;
// 	int tmp;

// 	e->tag.tag = 0;
// 	i = 0;
// 	if (fmt[e->i] >= '0' && fmt[e->i] <= '9')
// 	{
// 		tmp = ft_atoi(fmt + e->i);
// 		while (fmt[e->i + i] >= '0' && fmt[e->i + i] <= '9')
// 			i++;
// 		if (fmt[e->i + i] == '$')
// 		{
// 			e->tag.tag = 1;
// 			e->tag.pos = tmp;
// 			e->i += i + 1;
// 		}
// 	}
// }