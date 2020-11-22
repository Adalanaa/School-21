/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:56:18 by gyellowj          #+#    #+#             */
/*   Updated: 2020/07/16 09:56:20 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_printf.h"

int		ft_doit_percent(t_printf *ft, int i)
{
	int	doshir;

	doshir = ft->shirina - 1;
	if (ft->minus == 1)
	{
		ft_to_buffchar(ft, '%');
		while (doshir-- > 0)
			ft_to_buffchar(ft, ' ');
	}
	else
	{
		while (doshir-- > 0)
		{
			if (ft->null == 1)
				ft_to_buffchar(ft, '0');
			else
				ft_to_buffchar(ft, ' ');
		}
		ft_to_buffchar(ft, '%');
	}
	return (i + 1);
}
