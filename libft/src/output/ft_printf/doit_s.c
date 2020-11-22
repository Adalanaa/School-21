/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyellowj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:44:22 by gyellowj          #+#    #+#             */
/*   Updated: 2020/07/10 14:44:27 by gyellowj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_doit_s_with_minus(t_printf *ft, char *s, int doshir)
{
	if (ft->tchk == 1 && ft->tochn >= 0)
	{
		while (ft->tochn > 0 && *s)
		{
			ft_to_buffchar(ft, *s);
			ft->tochn--;
			s++;
		}
	}
	else
	{
		while (*s)
		{
			ft_to_buffchar(ft, *s);
			s++;
		}
	}
	while (doshir-- > 0)
		ft_to_buffchar(ft, ' ');
}

void		ft_doit_s_without_minus(t_printf *ft, char *s, int doshir)
{
	while (doshir-- > 0)
	{
		if (ft->null == 1)
			ft_to_buffchar(ft, '0');
		else
			ft_to_buffchar(ft, ' ');
	}
	if (ft->tchk == 1 && ft->tochn >= 0)
	{
		while (ft->tochn > 0 && *s)
		{
			ft_to_buffchar(ft, *s);
			ft->tochn--;
			s++;
		}
	}
	else
	{
		while (*s)
		{
			ft_to_buffchar(ft, *s);
			s++;
		}
	}
}

void		ft_doit_s(t_printf *ft)
{
	char	*s;
	int		doshir;

	s = va_arg(ft->arg, char *);
	if (s == NULL)
		s = "(null)";
	if (ft->tchk == 1 && ft->tochn >= 0 && ft->tochn < (int)ft_strlen(s))
		doshir = ft->shirina - ft->tochn;
	else
		doshir = ft->shirina - ft_strlen(s);
	if (ft->minus == 1)
		ft_doit_s_with_minus(ft, s, doshir);
	else
		ft_doit_s_without_minus(ft, s, doshir);
}
