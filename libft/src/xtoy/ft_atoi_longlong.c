/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_longlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:48:19 by kplums            #+#    #+#             */
/*   Updated: 2020/11/27 19:48:23 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoi_longlong(const char *str)
{
	int		flag;
	size_t	atoi;

	atoi = 0;
	flag = 1;
	while ((*str > 8 && *str < 14 && *str) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str && atoi <= 9223372036854775807)
	{
		atoi = atoi * 10 + (*str - '0');
		str++;
	}
	if (atoi >= 9223372036854775807 && flag == -1)
		return (0);
	else if (atoi >= 9223372036854775807 && flag == 1)
		return (-1);
	return (atoi * flag);
}
