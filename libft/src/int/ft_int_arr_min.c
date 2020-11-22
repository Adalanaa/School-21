/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:00:04 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 14:00:05 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_arr_min(int *arr, int size_arr)
{
	int i;
	int min;

	i = -1;
	min = arr[0];
	while (++i < size_arr)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	ft_memdel((void **)&arr);
	return (min);
}
