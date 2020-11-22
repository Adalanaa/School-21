/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:18 by kplums            #+#    #+#             */
/*   Updated: 2020/02/27 16:11:20 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include "stdint.h"

# define BUF_SIZE 2048

typedef struct	s_printf
{
	va_list		arg;

	int			i_buf;
	char		buf[BUF_SIZE];

	int			bytes;

	int			minus;
	int			plus;
	int			space;
	int			okt;
	int			null;

	int			shirina;
	int			tchk;
	int			tochn;

	int			size_hh;
	int			size_h;
	int			size_l;
	int			size_ll;
	int			size_big_l;
	int			size_j;

	int			flag;
	int			doshir;
	int			zero;
	int			len;
}				t_printf;

union			u_32_bit
{
	int			i;
	float		f;
}						;

int				ft_printf(const char *format, ...);

void			ft_doit(t_printf *ft, char *format);
int				ft_istip(char c);
int				ft_isflag(t_printf *ft, char c);
int				ft_shirina(t_printf *ft, char *format, int i);
int				ft_issize(t_printf *ft, char *format, int i);
int				ft_parser_format(t_printf *ft, char *format, int i);
int				is_nine(long long ld);

void			ft_doit_di(t_printf *ft);
void			ft_doit_o(t_printf *ft);
void			ft_doit_u(t_printf *ft);
void			ft_doit_x(t_printf *ft);
void			ft_doit_big_x(t_printf *ft);
void			ft_doit_ouxx(t_printf *ft, char *arr, uintmax_t num);
void			ft_doit_f(t_printf *ft);
void			ft_doit_lf(t_printf *ft);
void			ft_doit_c(t_printf *ft);
void			ft_doit_s(t_printf *ft);
void			ft_doit_p(t_printf *ft);
int				ft_doit_percent(t_printf *ft, int i);

void			ft_buff_write(t_printf *ft);
void			ft_to_buffchar(t_printf *ft, char c);
void			ft_to_buffstr(t_printf *ft, char *str);
void			ft_to_buffnbr(t_printf *ft, uintmax_t n);

#endif
