/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:53:48 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/20 16:57:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

void	ft_display_file(int file)
{
	char	buffer[BUFF_SIZE + 1];
	int		i;

	while (read(file, buffer, BUFF_SIZE))
	{
		i = 0;
		while (buffer[i])
			write(1, &buffer[i++], 1);
	}
}
