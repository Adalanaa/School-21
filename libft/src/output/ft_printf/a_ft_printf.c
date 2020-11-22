/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:43:59 by kplums            #+#    #+#             */
/*   Updated: 2020/02/27 17:44:00 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	ft;

	ft_bzero(&ft, sizeof(ft));
	va_start(ft.arg, format);
	ft_doit(&ft, (char *)format);
	ft_buff_write(&ft);
	va_end(ft.arg);
	return (ft.bytes);
}
