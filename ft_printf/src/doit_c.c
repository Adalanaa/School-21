/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:59:28 by gyellowj          #+#    #+#             */
/*   Updated: 2020/07/14 09:59:31 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_printf.h"

void				ft_doit_c(t_printf *ft)
{
	int				doshir;
	unsigned char	c;

	c = va_arg(ft->arg, int);
	doshir = ft->shirina - 1;
	if (ft->minus == 1)
	{
		ft_to_buffchar(ft, c);
		while (doshir-- > 0)
			ft_to_buffchar(ft, ' ');
	}
	else
	{
		while (doshir-- > 0)
			ft_to_buffchar(ft, ' ');
		ft_to_buffchar(ft, c);
	}
}
