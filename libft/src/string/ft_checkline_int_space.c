/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkline_int_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:52:54 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 18:52:57 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checkline_int_space(char *line)
{
	int		i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && ft_isdigit(line[i]) == 0 && line[i] != '-')
		{
			return (0);
		}
		if (line[i] == '-')
		{
			if (!(line[i + 1]) && ft_isdigit(line[i + 1]) == 0)
				return (0);
			if (i != 0 && ft_isdigit(line[i - 1]) == 1)
				return (0);
		}
		i++;
	}
	return (1);
}
