/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:31:05 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define DEBAG 1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_list1
{
	void			*content;
	size_t			content_size;
	struct s_list1	*next;
}					t_list1;

enum				e_errors
{
	AC = 1,
	MALLOC
};

int					ft_countarrtochar(char const *s, char c);
int					ft_lenarrtochar(char const *s, char c);
int					ft_newarrchar(char const *s, char c, char **arr);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

int					ft_int_abs(int a);
int					ft_abs_min(int a, int b);
int					ft_int_arr_check(int *arr, int ch_size, int data);
int					ft_int_arr_max(int *arr, int size_arr);
int					ft_int_arr_min(int *arr, int size_arr);
int					ft_int_max(int a, int b);
int					ft_int_min(int a, int b);

void				ft_lstadd(t_list1 **alst, t_list1 *new);
void				ft_lstdel(t_list1 **alst, void (*del)(void *, size_t));
void				ft_lstdelcont(void *content, size_t size);
void				ft_lstdelone(t_list1 **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list1 *lst, void (*f)(t_list1 *elem));
int					ft_lstlen(t_list1 *list);
t_list1				*ft_lstmap(t_list1 *lst, t_list1 *(*f)(t_list1 *elem));
t_list1				*ft_lstnew(void const *content, size_t content_size);

void				ft_bzero(void *s, size_t n);
void				*ft_malloc(size_t size, size_t sizeoff);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

void				ft_exit_error(int error);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);

int					checkline_int_space(char *line);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strcat(char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *hay, const char *n, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

int					ft_atoi(const char *str);
long long int		ft_atoi_longlong(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(uintmax_t value, int base, int sign);

size_t				ft_len_uintmax(uintmax_t nb, int base);

#endif
