/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:51:41 by sbednar           #+#    #+#             */
/*   Updated: 2018/12/19 01:48:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// typedef struct		s_list
// {
// 	void			*content;
// 	size_t			content_size;
// 	struct s_list	*next;
// }					t_list;

typedef struct		s_strlst
{
	char			*val;
	struct s_strlst	*next;
}					t_strlst;

typedef struct		s_token
{
	void			*content;
	size_t			content_size;
	// PARAMETERS
	struct s_token	*next;
}					t_token;

// void				*ft_memset(void *b, int c, size_t len);
// void				ft_bzero(void *s, size_t n);
// void				*ft_memcpy(void *dst, void const *src, size_t n);
// void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
// void				*ft_memmove(void *dst, void const *src, size_t len);
// void				*ft_memchr(void const *s, int c, size_t n);
// int					ft_memcmp(void const *s1, void const *s2, size_t n);
size_t				ft_strlen(char const *str);
char				*ft_strdup(char const *str);
// char				*ft_strcpy(char *dst, char const *src);
// char				*ft_strncpy(char *dst, char const *src, size_t len);
// char				*ft_strcat(char *s1, char const *s2);
// char				*ft_strncat(char *s1, char const *s2, size_t n);
// size_t				ft_strlcat(char *dst, char const *src, size_t dstsize);
// char				*ft_strchr(char const *s, int c);
// char				*ft_strrchr(char const *s, int c);
// char				*ft_strstr(char const *haystack, char const *needle);
// char				*ft_strnstr(char const *h, char const *n, size_t len);
// int					ft_strcmp(char const *s1, char const *s2);
// int					ft_strncmp(char const *s1, char const *s2, size_t n);
// int					ft_atoi(char const *str);
// int					ft_isalpha(int c);
// int					ft_isdigit(int c);
// int					ft_isalnum(int c);
// int					ft_isascii(int c);
// int					ft_isprint(int c);
// int					ft_toupper(int c);
// int					ft_tolower(int c);

// void				*ft_memalloc(size_t size);
// void				ft_memdel(void **ap);
// char				*ft_strnew(size_t size);
// void				ft_strdel(char **as);
// void				ft_strclr(char *s);
// void				ft_striter(char *s, void (*f)(char *));
// void				ft_striteri(char *s, void (*f)(unsigned int, char *));
// char				*ft_strmap(char const *s, char (*f)(char));
// char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// int					ft_strequ(char const *s1, char const *s2);
// int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
// char				*ft_strjoin(char const *s1, char const *s2);
// char				*ft_strtrim(char const *s);
// char				**ft_strsplit(char const *s, char c);
// char				*ft_itoa(int n);
// void				ft_putchar(char c);
// void				ft_putstr(char const *s);
// void				ft_putendl(char const *s);
// void				ft_putnbr(int n);
// void				ft_putchar_fd(char c, int fd);
// void				ft_putstr_fd(char const *s, int fd);
// void				ft_putendl_fd(char const *s, int fd);
// void				ft_putnbr_fd(int n, int fd);

// t_list				*ft_lstnew(void const *content, size_t content_size);
// void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
// void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
// void				ft_lstadd(t_list **alst, t_list *new);
// void				ft_lstadd_back(t_list **alst, t_list *new);
// void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
// t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

// int					ft_islower(int c);
// int					ft_isupper(int c);
// int					ft_isstn(char c);
// void				ft_putwchar(int wc);
// void				ft_putwchar_fd(int wc, int fd);
// char				*ft_strallcpy(char const *src, size_t len);
// size_t				ft_nbrlen(int n);
// size_t				ft_wordlen(char const *s, char c);
// size_t				ft_wordscnt(const char *str, char c);
// char				**ft_strsfree(char **src);
// void				ft_lstdels(t_list **alst);
// void				ft_lstdelones(t_list **alst);

t_token				*ft_token_new(void *c, size_t csize);
t_strlst			*ft_strlst_new(char *val);

t_token				*ft_token_add(t_token **head, t_token *node);
t_strlst			*ft_strlst_add(t_strlst **head, t_strlst *node);

t_token				*ft_token_add_new(t_token **head, void *c, size_t csize);
t_strlst			*ft_strlst_add_new(t_strlst **head, char *val);

t_strlst			*ft_strlst_add_substr(t_strlst **head, char *val,
					unsigned int start, size_t len);

int					ft_strlst_print(t_strlst *head);

void				ft_token_clear(t_token **head);
void				ft_strlst_clear(t_strlst **head);

#endif
