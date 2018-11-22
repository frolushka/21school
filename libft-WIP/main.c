/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:10:27 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/22 13:20:01 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*s = malloc(11);

	s = memset(s, 10, 14);
	int i = -1;
	while (++i < 11)
		printf("%d ", s[i]);
	return (0);
}
