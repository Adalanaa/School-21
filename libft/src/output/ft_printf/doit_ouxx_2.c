/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit_ouxx_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:00:38 by kplums            #+#    #+#             */
/*   Updated: 2020/07/24 17:00:39 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_oct_flag(t_printf *ft, char *p)
{
	char	*arr;

	arr = NULL;
	if (ft->flag == 1)
		arr = "0x";
	else if (ft->flag == 2)
		arr = "0X";
	else if (ft->flag == 3)
	{
		if (ft->tochn > 0)
		{
			if (ft->shirina > ft->tochn && ft->tochn > (int)ft_strlen(p))
			{
				if (ft->minus == 0)
					ft_to_buffchar(ft, ' ');
				else
					ft->doshir++;
			}
			ft->zero--;
		}
		arr = "0";
	}
	return (arr);
}

void		ft_doit_ouxx_number_minus_0(t_printf *ft, char *p)
{
	if (ft->null == 1 && ft->okt == 1 && ft->tchk == 0)
	{
		if (ft->zero < ft->doshir)
			ft->zero = ft->doshir;
		ft->doshir = 0;
	}
	while (ft->doshir-- > 0)
		if (ft->null == 0 || (ft->null == 1 && ft->tchk == 1))
			ft_to_buffchar(ft, ' ');
		else
			ft_to_buffchar(ft, '0');
	if (ft->okt == 1 && ft->flag > 0)
		ft_to_buffstr(ft, ft_oct_flag(ft, p));
	while (ft->zero-- > 0)
		ft_to_buffchar(ft, '0');
	ft_to_buffstr(ft, p);
}

void		ft_doit_ouxx_number_minus_1(t_printf *ft, char *p)
{
	if (ft->okt == 1 && ft->flag > 0)
		ft_to_buffstr(ft, ft_oct_flag(ft, p));
	while (ft->zero-- > 0)
		ft_to_buffchar(ft, '0');
	ft_to_buffstr(ft, p);
	while (ft->doshir-- > 0)
		ft_to_buffchar(ft, ' ');
}

void		ft_doit_ouxx_null(t_printf *ft, char *p)
{
	if (ft->minus == 0)
	{
		while (ft->doshir-- > 0)
			if (ft->null == 0 || (ft->null == 1 && ft->tchk == 1))
				ft_to_buffchar(ft, ' ');
			else
				ft_to_buffchar(ft, '0');
		if (ft->tchk == 0 || (ft->tchk == 1 && \
		(ft->tochn > 0 || (ft->tochn == 0 && ft->flag == 3))))
			ft_to_buffstr(ft, p);
		while (ft->zero-- > 0)
			ft_to_buffchar(ft, '0');
	}
	else
	{
		while (ft->zero-- > 0)
			ft_to_buffchar(ft, '0');
		if (ft->tchk == 0 || (ft->tchk == 1 && \
		(ft->tochn > 0 || (ft->tochn == 0 && ft->flag == 3))))
			ft_to_buffstr(ft, p);
		while (ft->doshir-- > 0)
			ft_to_buffchar(ft, ' ');
	}
}

void		ft_doit_ouxx(t_printf *ft, char *arr, uintmax_t num)
{
	ft->zero = ft->tochn - (int)(ft_strlen(arr));
	ft->doshir = ft->shirina - ft_int_max((int)(ft_strlen(arr)), ft->tochn);
	if (ft->okt == 1 && num != 0)
		ft->doshir--;
	if ((ft->okt == 1 && num != 0) && (ft->flag == 1 || ft->flag == 2))
		ft->doshir--;
	if (num == 0 && ft->tochn == 0 && ft->flag != 3)
		ft->doshir += ft->tchk;
	if (num == 0)
		ft_doit_ouxx_null(ft, arr);
	else
	{
		if (ft->minus == 0)
			ft_doit_ouxx_number_minus_0(ft, arr);
		else
			ft_doit_ouxx_number_minus_1(ft, arr);
	}
}
