/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:22:29 by kplums            #+#    #+#             */
/*   Updated: 2020/03/10 15:22:30 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_printf.h"

int	ft_isflag(t_printf *ft, char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		if (c == '-')
			ft->minus = 1;
		if (c == '+')
			ft->plus = 1;
		if (c == ' ')
			ft->space = 1;
		if (c == '#')
			ft->okt = 1;
		if (c == '0')
			ft->null = 1;
		return (1);
	}
	return (0);
}

int	ft_shirina(t_printf *ft, char *format, int i)
{
	if (format[i] && format[i] == '*')
	{
		ft->shirina = va_arg(ft->arg, int);
		if (ft->shirina < 0)
		{
			ft->shirina = -ft->shirina;
			ft->minus = 1;
		}
		i++;
	}
	if (format[i] && ft_isdigit(format[i]) > 0)
	{
		ft->shirina = ft_atoi(format + i);
		while (format[i] && ft_isdigit(format[i]) > 0)
			i++;
	}
	return (i);
}

int	ft_tochnost(t_printf *ft, char *format, int i)
{
	if (format[i] && format[i] == '.')
	{
		ft->tchk = 1;
		if (format[++i] && format[i] == '*')
		{
			ft->tochn = va_arg(ft->arg, int);
			if (ft->tochn < 0)
			{
				ft->tochn = 0;
				ft->tchk = 0;
			}
			i++;
		}
		if (format[i] && ft_isdigit(format[i]) > 0)
		{
			ft->tochn = ft_atoi(format + i);
			while (format[i] && ft_isdigit(format[i]) > 0)
				i++;
		}
	}
	return (i);
}

int	ft_issize(t_printf *ft, char *format, int i)
{
	if (format[i] == 'L')
		ft->size_big_l = 1;
	if (format[i + 1] && format[i] == format[i + 1])
	{
		if (format[i] == 'h')
			ft->size_hh = 1;
		else
			ft->size_ll = 1;
		return (i + 2);
	}
	if (format[i] == 'h')
		ft->size_h = 1;
	if (format[i] == 'l')
		ft->size_l = 1;
	return (i + 1);
}

int	ft_parser_format(t_printf *ft, char *format, int i)
{
	if (format[++i] && format[i] == '%')
	{
		ft_to_buffchar(ft, format[i]);
		return (i + 1);
	}
	while (format[i] && ft_isflag(ft, format[i]) > 0)
		i++;
	if (format[i])
		i = ft_shirina(ft, format, i);
	if (format[i])
		i = ft_tochnost(ft, format, i);
	while (format[i] && ft_strchr("hlL", format[i]))
		i = ft_issize(ft, format, i);
	if (format[i] && format[i] == '%')
		i = ft_doit_percent(ft, i);
	return (i);
}
