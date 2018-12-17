/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdlms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:47:04 by edraugr-          #+#    #+#             */
/*   Updated: 2018/12/17 22:02:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkdlms(char c, const char *dlms)
{
	int	i;

	i = -1;
	while (dlms[++i])
		if (ft_checkdlm(c, dlms[i]))
			return (1);
	return (0);
}
