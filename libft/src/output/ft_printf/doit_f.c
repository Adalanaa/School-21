/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:14:46 by gyellowj          #+#    #+#             */
/*   Updated: 2020/03/10 18:14:50 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					is_nine(long long ld)
{
	int				flag;

	flag = ld == 0 ? 0 : 1;
	while (ld)
	{
		if (ld % 10 != 9)
			flag = 0;
		ld /= 10;
	}
	return (flag);
}

void				ft_f_print(t_printf *ft, double d, long long d_int)
{
	ft_to_buffnbr(ft, d_int);
	if (ft->tochn > 0 || ft->okt)
		ft_to_buffchar(ft, '.');
	while (ft->zero-- > 0)
		ft_to_buffchar(ft, '0');
	if (ft->tochn > 0 && d >= 1)
		ft_to_buffnbr(ft, (long long)d);
	if ((ft->null || ft->minus) && ft->shirina > 0)
	{
		while (ft->shirina > 0)
		{
			if (ft->null && !ft->minus)
				ft_to_buffchar(ft, '0');
			else
				ft_to_buffchar(ft, ' ');
			ft->shirina--;
		}
	}
}

void				ft_f_okr(t_printf *ft, double d, long long d_int, int i)
{
	while (i++ < ft->tochn)
	{
		d *= 10;
		if (d < 0.9)
			ft->zero++;
	}
	if (d - (long long)d >= 0.5)
	{
		if (is_nine((long long)d) && !ft->zero)
		{
			d_int++;
			ft->len = ft_len_uintmax(d >= 0 ? d : -d, 10);
			while (ft->len-- > 0)
				ft->zero++;
			d = 0;
		}
		d_int = d_int % 2 == 1 && ft->tochn == 0 ? d_int + 1 : d_int;
		if (ft->tochn == 0 && d_int == 0 && d != 0.5)
			d_int++;
		d += 0.5;
	}
	ft_f_print(ft, d, d_int);
}

void				ft_f_shirina(t_printf *ft, int isneg)
{
	if ((ft->len ? ft->len : 1) + (ft->tochn > 0 ? 1 : 0) +
		(isneg || ft->plus || ft->space ? 1 : 0) + (ft->okt && !ft->tochn) +
		ft->tochn > ft->shirina)
		ft->shirina = 0;
	else
		ft->shirina = ft->shirina - (ft->len ? ft->len : 1) -
		(ft->tochn > 0 ? 1 : 0) - (isneg || ft->plus || ft->space ? 1 : 0) -
		(ft->okt && !ft->tochn) - ft->tochn;
	if (ft->space && !ft->plus && !isneg)
		ft_to_buffchar(ft, ' ');
	while (!ft->null && !ft->minus && ft->shirina > 0)
	{
		ft_to_buffchar(ft, ' ');
		ft->shirina--;
	}
	if (!isneg && ft->plus)
		ft_to_buffchar(ft, '+');
	if (isneg)
		ft_to_buffchar(ft, '-');
	while (ft->null && !ft->minus && ft->shirina > 0)
	{
		ft_to_buffchar(ft, '0');
		ft->shirina--;
	}
}

void				ft_doit_f(t_printf *ft)
{
	union u_32_bit	data;
	int				isneg;
	long long		d_int;
	double			d;

	if (ft->size_big_l)
		ft_doit_lf(ft);
	else
	{
		d = va_arg(ft->arg, double);
		data.f = d;
		isneg = ((data.i >> 31 & 1) == 1) ? 1 : 0;
		if (!ft->tchk || ft->tochn < 0)
			ft->tochn = 6;
		d = isneg ? -d : d;
		d_int = (long long)d;
		d = d - (long long)d_int;
		ft->len = ft_len_uintmax(d_int >= 0 ? d_int : -d_int, 10);
		ft_f_shirina(ft, isneg);
		ft_f_okr(ft, d, d_int, 0);
	}
}
