/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:26:18 by gyellowj          #+#    #+#             */
/*   Updated: 2020/07/24 21:26:20 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_lf_print(t_printf *ft, long double ld, long long ld_int)
{
	ft_to_buffnbr(ft, ld_int);
	if (ft->tochn > 0 || ft->okt)
		ft_to_buffchar(ft, '.');
	while (ft->zero-- > 0)
		ft_to_buffchar(ft, '0');
	if (ft->tochn > 0 && ld >= 1)
		ft_to_buffnbr(ft, (long long)ld);
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

void				ft_lf_okr(t_printf *ft, double ld, long long ld_int, int i)
{
	while (i++ < ft->tochn)
	{
		ld *= 10;
		if (ld < 0.9)
			ft->zero++;
	}
	if (ld - (long long)ld >= 0.5)
	{
		if (is_nine((long long)ld) && !ft->zero)
		{
			ld_int++;
			ft->len = ft_len_uintmax(ld >= 0 ? ld : -ld, 10);
			while (ft->len-- > 0)
				ft->zero++;
			ld = 0;
		}
		ld_int = ld_int % 2 == 1 && ft->tochn == 0 ? ld_int + 1 : ld_int;
		if (ft->tochn == 0 && ld_int == 0 && ld != 0.5)
			ld_int++;
		ld += 0.5;
	}
	ft_lf_print(ft, ld, ld_int);
}

void				ft_lf_shirina(t_printf *ft, int isneg)
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

void				ft_doit_lf(t_printf *ft)
{
	union u_32_bit	data;
	int				isneg;
	long long		ld_int;
	long double		ld;
	int				i;

	i = 0;
	ld = va_arg(ft->arg, long double);
	data.f = ld;
	isneg = ((data.i >> 31 & 1) == 1) ? 1 : 0;
	if (!ft->tchk || ft->tochn < 0)
		ft->tochn = 6;
	ld = isneg ? -ld : ld;
	ld_int = (long long)ld;
	ld = ld - (long long)ld_int;
	ft->len = ft_len_uintmax(ld_int >= 0 ? ld_int : -ld_int, 10);
	ft_lf_shirina(ft, isneg);
	ft_lf_okr(ft, ld, ld_int, i);
}
