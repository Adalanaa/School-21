/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:01:22 by kplums            #+#    #+#             */
/*   Updated: 2019/12/08 18:01:24 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define ABS(x) (x > 0 ? x : -x)

int     *ft_rrange(int start, int end)
{
	int*	range;
	int		i;
	i = 0;

	range = (int *)malloc(sizeof(int) * (ABS((end - start)) + 1));
	while (i <= ABS((end - start)))
	{
		if (end - start >= 0)
			range[i] = end - i;
		else
			range[i] = end + i;
		i++;
	}
	return (range);
}
