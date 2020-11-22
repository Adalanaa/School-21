/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:09:27 by kplums            #+#    #+#             */
/*   Updated: 2020/07/24 17:09:28 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <func_printf.h>

void			ft_doit_p_minus_1(t_printf *ft, char *p, int doshir, int zero)
{
	ft_to_buffstr(ft, "0x");
	if (ft_strcmp(p, "0") != 0 || (ft_strcmp(p, "0") == 0 && (ft->tchk == 0 \
	|| (ft->tchk == 1 && ft->tochn > 0))))
		ft_to_buffstr(ft, p);
	while (zero-- > 0)
		ft_to_buffchar(ft, '0');
	while (doshir-- > 0)
		ft_to_buffchar(ft, ' ');
}

void			ft_doit_p_minus_0(t_printf *ft, char *p, int doshir, int zero)
{
	while (doshir-- > 0)
		ft_to_buffchar(ft, ' ');
	ft_to_buffstr(ft, "0x");
	while (zero-- > 0)
		ft_to_buffchar(ft, '0');
	if (ft_strcmp(p, "0") != 0 || (ft_strcmp(p, "0") == 0 && (ft->tchk == 0 \
	|| (ft->tchk == 1 && ft->tochn > 0))))
		ft_to_buffstr(ft, p);
}

void			ft_doit_p(t_printf *ft)
{
	int			doshir;
	int			zero;
	char		*p;
	intmax_t	adress;

	adress = va_arg(ft->arg, intmax_t);
	p = ft_itoa_base(adress, 16, 0);
	zero = ft->tochn - (int)(ft_strlen(p));
	doshir = ft->shirina - 2 - ft_max_int((int)(ft_strlen(p)), ft->tochn);
	if (adress == 0 && ft->tochn == 0)
		doshir += ft->tchk;
	if (ft->minus == 1)
		ft_doit_p_minus_1(ft, p, doshir, zero);
	else
		ft_doit_p_minus_0(ft, p, doshir, zero);
	if (adress != 0)
		ft_strdel(&p);
}
