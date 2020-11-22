/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:53:38 by kplums            #+#    #+#             */
/*   Updated: 2020/07/20 14:53:39 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_null(t_printf *ft)
{
	if (ft->tochn == 0 && ft->tchk == 1)
		return ;
	else
		ft_to_buffchar(ft, '0');
}

void	ft_doit_di_with_minus(t_printf *ft, intmax_t lldi)
{
	if (ft->plus == 1 && lldi >= 0)
		ft_to_buffchar(ft, '+');
	if (lldi < 0)
		ft_to_buffchar(ft, '-');
	if (lldi >= 0 && ft->plus == 0 && ft->space == 1)
	{
		ft_to_buffchar(ft, ' ');
		ft->doshir--;
	}
	while (ft->zero-- > 0)
		ft_to_buffchar(ft, '0');
	if (lldi == 0)
		ft_putnbr_null(ft);
	else if (lldi > 0)
		ft_to_buffnbr(ft, lldi);
	else
		ft_to_buffnbr(ft, -lldi);
	while (ft->doshir-- > 0)
		ft_to_buffchar(ft, ' ');
}

void	ft_doit_di_without_minus(t_printf *ft, intmax_t lldi)
{
	if (ft->space == 1 && (ft->null == 0 || (lldi >= 0 && ft->plus == 0)) \
	&& lldi >= 0)
	{
		ft_to_buffchar(ft, ' ');
		ft->doshir--;
	}
	if ((ft->null == 0 || ft->tchk == 1) && ft->tochn >= 0)
		while (ft->doshir-- > 0)
			ft_to_buffchar(ft, ' ');
	if (ft->plus == 1 && lldi >= 0)
		ft_to_buffchar(ft, '+');
	if (lldi < 0)
		ft_to_buffchar(ft, '-');
	if ((ft->null == 0 || ft->tchk == 1) && ft->tochn >= 0)
		while (ft->zero-- > 0)
			ft_to_buffchar(ft, '0');
	else
		while (ft->doshir-- > 0)
			ft_to_buffchar(ft, '0');
	if (lldi == 0)
		ft_putnbr_null(ft);
	else if (lldi > 0)
		ft_to_buffnbr(ft, lldi);
	else
		ft_to_buffnbr(ft, -lldi);
}

void	ft_di(t_printf *ft, intmax_t lldi)
{
	int len_uns_lldi;

	len_uns_lldi = ft_len_uintmax(lldi >= 0 ? lldi : -lldi, 10);
	ft->zero = ft->tochn - len_uns_lldi;
	if (ft->shirina >= ft->tochn + 1)
		ft->doshir = ft->shirina - len_uns_lldi;
	else
		ft->doshir = ft->tochn - len_uns_lldi;
	if (ft->zero > 0)
		ft->doshir -= ft->zero;
	if (lldi < 0 || (lldi >= 0 && ft->plus == 1) || \
	(ft->space == 0 && ft->zero > 0 && ft->minus == 1 && \
	ft->shirina <= ft->tochn))
		ft->doshir--;
	if (lldi == 0 && ft->tchk == 1 && ft->tochn == 0)
		ft->doshir++;
	if (ft->minus == 1)
		ft_doit_di_with_minus(ft, lldi);
	else
		ft_doit_di_without_minus(ft, lldi);
}

void	ft_doit_di(t_printf *ft)
{
	intmax_t	di;

	di = va_arg(ft->arg, intmax_t);
	if (ft->size_l == 0 && ft->size_ll == 0 && ft->size_j == 0)
		di = (int)di;
	if (ft->size_h == 1)
		di = (short)di;
	if (ft->size_hh == 1 && ft->size_l == 0 && ft->size_ll == 0 \
	&& ft->size_j == 0)
		di = (signed char)di;
	if (ft->plus == 1)
		ft->space = 0;
	ft_di(ft, di);
}
