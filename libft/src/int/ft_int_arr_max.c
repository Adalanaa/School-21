/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:58:57 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 13:59:00 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_arr_max(int *arr, int size_arr)
{
	int i;
	int max;

	i = -1;
	max = arr[0];
	while (++i < size_arr)
		if (arr[i] > max)
			max = arr[i];
	ft_memdel((void **)&arr);
	return (max);
}
