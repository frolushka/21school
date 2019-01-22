/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:45:19 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/18 03:39:40 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ddd.h"
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>

# define SCREEN_X 1920
# define SCREEN_Y 1080
# define SCREEN_NAME "fdf"

t_vec2	*check_valid(int fd);
t_vec4	**read_vecs(char *fn);

#endif
