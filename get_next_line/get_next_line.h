/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:18:53 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/02 13:37:44 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define EOF (-1)
# define BUFF_SIZE 32
# define IFRET1(x) if (x) return (1);
# define IFRET0(x) if (x) return (0);
# define IFRETN1(x) if (x) return (-1);

int		get_next_line(int const fd, char **line);

#endif
