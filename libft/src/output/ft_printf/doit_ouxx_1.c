/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit_ouxx_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:15:45 by kplums            #+#    #+#             */
/*   Updated: 2020/07/24 17:15:47 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ft_va_arg_ou(t_printf *ft)
{
	uintmax_t	ouxx;

	ouxx = va_arg(ft->arg, uintmax_t);
	if (ft->size_l == 0 && ft->size_ll == 0 && ft->size_j == 0)
		ouxx = (unsigned int)ouxx;
	if (ft->size_h == 1)
		ouxx = (unsigned short)ouxx;
	if (ft->size_hh == 1 && ft->size_l == 0 && ft->size_ll == 0 \
	&& ft->size_j == 0)
		ouxx = (unsigned char)ouxx;
	return (ouxx);
}

void			ft_doit_o(t_printf *ft)
{
	uintmax_t	o;
	char		*o_arr;

	o = ft_va_arg_ou(ft);
	o_arr = ft_itoa_base(o, 8, 0);
	if (ft->okt == 1)
		ft->flag = 3;
	ft_doit_ouxx(ft, o_arr, o);
	if (o != 0)
		ft_strdel(&o_arr);
}

void			ft_doit_u(t_printf *ft)
{
	uintmax_t	u;
	char		*u_arr;

	u = ft_va_arg_ou(ft);
	u_arr = ft_itoa_base(u, 10, 0);
	ft_doit_ouxx(ft, u_arr, u);
	if (u != 0)
		ft_strdel(&u_arr);
}

void			ft_doit_x(t_printf *ft)
{
	uintmax_t	x;
	char		*arr;

	x = ft_va_arg_ou(ft);
	arr = ft_itoa_base(x, 16, 0);
	if (ft->okt == 1)
		ft->flag = 1;
	ft_doit_ouxx(ft, arr, x);
	if (x != 0)
		ft_strdel(&arr);
}

void			ft_doit_big_x(t_printf *ft)
{
	int			i;
	char		*arr;
	uintmax_t	x;

	x = ft_va_arg_ou(ft);
	arr = ft_itoa_base(x, 16, 0);
	i = -1;
	while (x != 0 && arr[++i] != '\0')
		arr[i] = ft_toupper(arr[i]);
	if (ft->okt == 1)
		ft->flag = 2;
	ft_doit_ouxx(ft, arr, x);
	if (x != 0)
		ft_strdel(&arr);
}
