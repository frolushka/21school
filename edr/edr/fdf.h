/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:20:13 by edraugr-          #+#    #+#             */
/*   Updated: 2019/01/23 04:09:59 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "lowlvlddd.h"
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_X 1920
# define SCREEN_Y 1080
# define SCREEN_NAME "fdf"

int			read_dots(char *fn, t_dots **res);
void		solve_dots(t_dots *dots, const t_cam *cam);
int			print_dots(t_dots *res);

void		fill_screen(t_dots **d);
void		connect_dots(const t_mlx *c, t_dots **d);
void		redraw(const t_mlx *c, t_dots *dots, const t_cam *cam);
int			hook_mouse_move(int x, int y, t_mouse *mouse);
int			key_hook(const int key, t_mouse *mouse);
int			hook_wheel(int key, int x, int y, t_mouse *m);

// old reader

int			check_line_valid(char **line);
int			fill_dots(char *fn, t_dots **res);
int			get_size(char *fn, t_vec2 **res);
int			print_dots(t_dots *res);
int			read_dots(char *fn, t_dots **res);

int			get_color(char const *it);
int			free_all(char **line, char ***tmp, int fd);

int	hook_rot_debug(int key, t_mouse *mouse);

#endif
