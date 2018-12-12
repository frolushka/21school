/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelones.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:35:56 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/27 23:37:13 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelones(t_list **alst)
{
	if (!alst)
		return ;
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
