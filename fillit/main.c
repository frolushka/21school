/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:14:17 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/04 17:44:38 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "barray/ft_barray.h"

int	main(void)
{
	t_barray *ba = ft_ba_init(4);
	ft_ba_set(ba, 4, 1);
	ft_ba_print(ba);
	ft_ba_set(ba, 10, 1);
	ft_ba_print(ba);
	ft_ba_set(ba, 2, 1);
	ft_ba_print(ba);
	ft_ba_set(ba, 4, 0);
	ft_ba_print(ba);
	ft_ba_set(ba, 13, 1);
	ft_ba_print(ba);
	return (0);
}