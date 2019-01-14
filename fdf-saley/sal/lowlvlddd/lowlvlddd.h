/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowlvlddd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:56:09 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/14 17:02:55 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOWLVLDDD_H
# define LOWLVLDDD_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>

# define FUNC_KO 0
# define FUNC_INV_PRM -1
# define FUNC_OK 1

# define ABS(x) (((x) >= 0) ? (x) : (-(x)))
# define SIGN(x) ((x) >= 0 ? 1 : -1)

typedef struct		s_config
{
	int				screen_x;
	int				screen_y;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_config;

typedef struct		s_prim_info
{
	int				param;
	int				color;
	void			**content;
	int				size;
}					t_info;

typedef struct		s_vector2
{
	int				x;
	int				y;
}					t_vector2;

typedef struct		s_vector3
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

typedef struct		s_vector4
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector4;

typedef struct		s_mtx
{
	double			*mtx;
	unsigned int	r;
	unsigned int	c;
}					t_mtx;

typedef struct		s_dots
{
	int				count;
	int				xc;
	int				yc;
	t_vector3		*local;
	t_vector3		*cam;
	t_vector2		*screen;
	int				*color;
}					t_dots;

t_dots				*init_dots(int fd);

t_config			*init_conf(void *mlx, void *win);
t_vector2			*init_vector2(int x, int y);
t_info				*init_info(int param, int color, int size, void **content);
void				info_cpy_contall(t_info *dst, const t_info *src, size_t n);

int					ddd_draw_line(const t_config *config, const t_info *param);
int					ddd_draw_rect(t_config *config, t_info *param);
int					ddd_draw_lines_arr(const t_config *c, const t_info *prm);

#endif
