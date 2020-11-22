/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:42:12 by unite             #+#    #+#             */
/*   Updated: 2019/07/14 13:05:49 by tfelisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str += 1;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i += 1;
	while (*src)
		dest[i++] = *(src++);
	dest[i] = '\0';
	return (dest);
}
