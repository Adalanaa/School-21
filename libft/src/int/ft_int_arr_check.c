/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:11:00 by kplums            #+#    #+#             */
/*   Updated: 2020/11/12 14:11:01 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_arr_check(int *arr, int ch_size, int data)
{
	int	i;

	i = 0;
	while (i < ch_size)
		if (arr[i++] == data)
			return (1);
	return (0);
}
