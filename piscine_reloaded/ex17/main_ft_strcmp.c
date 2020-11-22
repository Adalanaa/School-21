/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:55:14 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*s1;
	char	*s2;
	int		cmp;

	s1 = "Hello";
	s2 = "Hello";
	cmp = ft_strcmp(s1, s2);
	printf("%d\n", cmp);
	cmp = strcmp(s1, s2);
	printf("%d\n", cmp);
	return (0);
}
