/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:40:53 by kplums            #+#    #+#             */
/*   Updated: 2020/03/01 14:40:54 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "ft_printf.h"
#	include <stdio.h>
#	include <math.h>
#	include <limits.h>

#	define FLAG ""
#	define FORMAT "%f" FLAG ""
#	define ARG 12345.6, -12345.6
#	define FORMATARG "%.15f",  0.999999999999999900

int	main(void)
{
	printf(FORMATARG);
	printf("}\n");
	ft_printf(FORMATARG);
	ft_printf("}\n");
	return (0);
}
