/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:08:03 by kplums            #+#    #+#             */
/*   Updated: 2020/07/24 17:08:05 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_printf.h"

void		ft_clean_ft(t_printf *ft)
{
	ft->minus = 0;
	ft->plus = 0;
	ft->space = 0;
	ft->okt = 0;
	ft->null = 0;
	ft->shirina = 0;
	ft->tchk = 0;
	ft->tochn = 0;
	ft->size_hh = 0;
	ft->size_h = 0;
	ft->size_l = 0;
	ft->size_ll = 0;
	ft->size_big_l = 0;
	ft->flag = 0;
	ft->zero = 0;
	ft->doshir = 0;
	ft->len = 0;
}

void		ft_do_put(void (*ft_doit[11])(t_printf *ft))
{
	ft_doit[1] = ft_doit_di;
	ft_doit[2] = ft_doit_di;
	ft_doit[3] = ft_doit_o;
	ft_doit[4] = ft_doit_u;
	ft_doit[5] = ft_doit_x;
	ft_doit[6] = ft_doit_big_x;
	ft_doit[7] = ft_doit_f;
	ft_doit[8] = ft_doit_c;
	ft_doit[9] = ft_doit_s;
	ft_doit[10] = ft_doit_p;
}

int			ft_istip(char c)
{
	int		i;
	char	*spisok;

	i = 1;
	spisok = " diouxXfcsp";
	while (spisok[i])
	{
		if (spisok[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int			ft_check_other_char(t_printf *ft, char *format, int i)
{
	int		j;
	char	time_buff[100];

	j = 0;
	ft_bzero(&time_buff, 100);
	while (format[i] && ft_istip(format[i]) == 0 && format[i] != '%')
	{
		time_buff[j] = format[i];
		i++;
		j++;
	}
	if (format[i] == '\0' || format[i] == '%')
	{
		j = -1;
		while (time_buff[++j] != '\0')
			ft_to_buffchar(ft, time_buff[j]);
	}
	return (i);
}

void		ft_doit(t_printf *ft, char *format)
{
	int		i;
	void	*(*ft_doit[11])(t_printf *ft);

	i = 0;
	ft_do_put((void (**)(t_printf *))ft_doit);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			ft_to_buffchar(ft, format[i]);
			i++;
		}
		if (format[i] && (format[i + 1] && format[i + 1] != '%'))
		{
			i = ft_parser_format(ft, format, i);
			i = ft_check_other_char(ft, format, i);
			if (format[i] && ft_istip(format[i]) > 0)
				ft_doit[ft_istip(format[i++])](ft);
			ft_clean_ft(ft);
		}
		else if (format[i] && (format[i + 1] && format[i++ + 1] == '%'))
			ft_to_buffchar(ft, format[i++]);
		else if (format[i + 1] == '\0')
			break ;
	}
}
