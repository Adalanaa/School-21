/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_iterative_factorial.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:09:41 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt(int nb);

int		main(void)
{
	int nb;
	int fact;

	nb = 0;
	fact = ft_sqrt(nb);
	printf("%d\n", fact);
	nb = 214748364;
	fact = ft_sqrt(nb);
	printf("%d\n", fact);
	nb = 317409856;
	fact = ft_sqrt(nb);
	printf("%d\n", fact);
	nb = 152280593;
	fact = ft_sqrt(nb);
	printf("%d\n", fact);
	nb = 790846884;
	fact = ft_sqrt(nb);
	printf("%d\n", fact);
	nb = 93317314;
	fact = ft_sqrt(nb);
	printf("%d\n", fact);
	nb = 1910301849;
	fact = ft_sqrt(nb);
	printf("%d\n", fact);
	return (0);
}
