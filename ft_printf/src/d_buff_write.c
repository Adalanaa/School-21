/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:22:47 by kplums            #+#    #+#             */
/*   Updated: 2020/03/10 15:22:48 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func_printf.h"

void	ft_buff_write(t_printf *ft)
{
	ft->bytes += ft->i_buf;
	write(1, ft->buf, ft->i_buf);
	ft->i_buf = 0;
	ft_bzero(ft->buf, sizeof(ft->buf));
}

void	ft_to_buffchar(t_printf *ft, char c)
{
	if (ft->i_buf == BUF_SIZE - 2)
		ft_buff_write(ft);
	ft->buf[ft->i_buf] = c;
	ft->i_buf++;
}

void	ft_to_buffstr(t_printf *ft, char *str)
{
	if (str != NULL)
		while (*str != '\0')
			ft_to_buffchar(ft, *str++);
	else
	{
		ft_to_buffchar(ft, '0');
		ft_to_buffchar(ft, 'x');
		if (ft->tchk == 0)
			ft_to_buffchar(ft, '0');
	}
}

void	ft_to_buffnbr(t_printf *ft, uintmax_t n)
{
	if (n > 9)
	{
		ft_to_buffnbr(ft, n / 10);
	}
	if (n >= 0)
		ft_to_buffchar(ft, n % 10 + '0');
}
