/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:58:11 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int		main(void)
{
	int a;
	int b;
	int div1;
	int mod1;
	int *div;
	int *mod;

	div = &div1;
	mod = &mod1;
	a = 10;
	b = 6;
	printf("%d %d\n", a, b);
	ft_div_mod(a, b, div, mod);
	printf("%d %d %d %d \n", a, b, div1, mod1);
	return (0);
}
