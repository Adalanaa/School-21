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

int		ft_recursive_factorial(int nb);

int		main(void)
{
	int nb;
	int fact;

	nb = -10;
	fact = ft_recursive_factorial(nb);
	printf("%d\n", fact);
	nb = 0;
	fact = ft_recursive_factorial(nb);
	printf("%d\n", fact);
	nb = 1;
	fact = ft_recursive_factorial(nb);
	printf("%d\n", fact);
	nb = 5;
	fact = ft_recursive_factorial(nb);
	printf("%d\n", fact);
	nb = 18;
	fact = ft_recursive_factorial(nb);
	printf("%d\n", fact);
	return (0);
}
