/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:51:41 by sbednar           #+#    #+#             */
/*   Updated: 2018/11/22 12:21:15 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void 	*ft_memccpy(void *dst, void const *src, int c, size_t n);
void 	*ft_memmove(void *dst, void const *src, size_t len);
void 	*ft_memchr(void const *s, int c, size_t n);
int		ft_memcmp(void const *s1, void const *s2, size_t n);
size_t	ft_strlen(char const *s);
char 	*ft_strdup(char const *s1);
char	*ft_stpcpy(char *dst, char const *src);
char	*ft_stpncpy(char *dst, char const *src, size_t len);

#endif
