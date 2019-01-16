/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:56:09 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/15 23:45:52 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOWLVLDDD_H
# define LOWLVLDDD_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define FUNC_KO 0
# define FUNC_INV_PRM -1
# define FUNC_OK 1

typedef unsigned short uint16_t;

# define ABS(x) ( ((x) >= 0) ? (x) : -(x) )
# define SIGN(x) (x >= 0 ? 1 : -1)

typedef struct		s_mlx
{
	int				width;
	int				height;
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_mtx
{
	float			*mtx;
	uint16_t		r;
	uint16_t		c;
}					t_mtx;

t_mlx				*ddd_mlx_init(int width, int height, char *header);

// int					ddd_draw_dot(t_mlx *mlx, t_info *params);  //todo
// int					ddd_draw_line(t_mlx const *mlx, t_info const *param);  //todo
// int					ddd_draw_rect(t_mlx *mlx, t_info *param);

t_vec2				*vec2_init(void);
t_vec2				*vec2_new(int const x, int const y);
t_vec2				*vec2_opp(t_vec2 const *v);
t_vec2				*vec2_sum(t_vec2 const *v1, t_vec2 const *v2);
t_vec2				*vec2_mult(t_vec2 const *v, float const s);
t_vec2				*vec2_copy(t_vec2 const *v);
void				vec2_print(t_vec2 const *v);

t_vec3				*vec3_init(void);
t_vec3				*vec3_new(int const x, int const y, int const z);
t_vec3				*vec3_opp(t_vec3 const *v);
t_vec3				*vec3_sum(t_vec3 const *v1, t_vec3 const *v2);
void				vec3_print(t_vec3 const *v);

t_vec4				*vec4_init(void);
t_vec4				*vec4_opp(t_vec4 const *v);
t_vec4				*vec4_sum(t_vec4 const *v1, t_vec4 const *v2);
void				vec4_print(t_vec4 const *v);

int					draw_line(t_mlx const *mlx, t_vec2 const *v1, t_vec2 const *v2);

t_vec2				*to_screen(t_vec3 *w);

t_mtx				*ddd_mtx_init(uint16_t const r, uint16_t const c);

#endif
