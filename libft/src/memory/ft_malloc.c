/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:22:37 by kplums            #+#    #+#             */
/*   Updated: 2020/11/17 15:22:38 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size, size_t sizeoff)
{
	void *arr;

	if (!(arr = (void *)malloc(size * sizeoff)))
		ft_exit_error(MALLOC);
	ft_bzero(arr, size);
	return (arr);
}
