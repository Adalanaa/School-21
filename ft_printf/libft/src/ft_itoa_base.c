/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:24:45 by kplums            #+#    #+#             */
/*   Updated: 2020/07/24 14:24:47 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

size_t	ft_len_uintmax(uintmax_t nb, int base)
{
	size_t	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(uintmax_t value, int base, int sign)
{
	int		i;
	int		len;
	char	*arr;
	char	*tab_base;

	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return ("0");
	tab_base = "0123456789abcdef";
	len = ft_len_uintmax(value, base);
	len += (sign ? 1 : 0);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	i = 1;
	sign ? (arr[0] = '-') : 0;
	while (value != 0)
	{
		arr[len - i++] = tab_base[value % base];
		value /= base;
	}
	arr[len] = '\0';
	return (arr);
}
