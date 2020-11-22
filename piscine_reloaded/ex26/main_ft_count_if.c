/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_count_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:48:37 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count_if(char **tab, int(*f)(char*));
int	ft_strlen(char *str);

int	main(int ac, char **av)
{
	int		n;
	n = 0;

	if (ac)
		n = ft_count_if(av, ft_strlen);
	printf("%d\n", n);
	return (0);
}