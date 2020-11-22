/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_abs_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:11:05 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 14:11:06 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs_min(int a, int b)
{
	int mod_a;
	int mod_b;

	mod_a = a;
	mod_b = b;
	if (mod_a < 0)
		mod_a = -mod_a;
	if (mod_b < 0)
		mod_b = -mod_b;
	if (mod_a - mod_b < 0)
		return (1);
	else if (mod_a - mod_b > 0)
		return (2);
	else
		return (0);
}
