/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 00:47:30 by sbednar           #+#    #+#             */
/*   Updated: 2019/01/02 23:51:30 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_info
{
	char			*tmp;
	va_list			va;
	int				fd;
	int				cfs;
	int				pre;
	int				wid;
	int				ind;
	int				bas;
	int				len;
}					t_info;

# define FLAGS		"0123456789hljz#-+. "
# define PREC		"fageFAGE"
# define NUMBER		"diouxX"

// # define CONV_c		1
// # define CONV_s 	1 << 1
// # define CONV_p 	1 << 2
// # define CONV_d 	1 << 3
// # define CONV_i 	1 << 4
// # define CONV_o 	1 << 5
// # define CONV_u 	1 << 6
// # define CONV_x 	1 << 7
// # define CONV_X 	1 << 8
// # define CONV_f		1 << 9

# define FLAG_h		1
# define FLAG_hh	(1u << 1)
# define FLAG_l		(1u << 2)
# define FLAG_ll	(1u << 3)
# define FLAG_L		(1u << 4)
# define FLAG_sharp	(1u << 5)
# define FLAG_zero	(1u << 6)
# define FLAG_minus	(1u << 7)
# define FLAG_plus	(1u << 8)
# define FLAG_space	(1u << 9)

# define FLAG_z		(1u << 10)
# define FLAG_j		(1u << 11)
# define FLAG_t		(1u << 12)

# define FLAG_up	(1u << 13)
# define FLAG_neg	(1u << 14)

int					ft_printf(char const *f, ...);

void				set_spec(t_info *i, char const *f);
// void inline			set_spec_2(t_info *i, char const *f);
void 				set_flag(t_info *i, char const *f);

void				prep_char(t_info *i);
void				prep_string(t_info *i);
void				prep_address(t_info *i);

void				prep_number(t_info *i);
void				prep_unumber(t_info *i);

void				print_char(t_info *i);
void				print_string(t_info *i);
void				print_address(t_info *i);
void				print_null(t_info *i);

void				print_number(t_info *i);
void				print_unumber(t_info *i);

void				print_percent(t_info *i);

#endif