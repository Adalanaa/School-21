/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:06:52 by kplums            #+#    #+#             */
/*   Updated: 2020/11/15 19:06:54 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_error(int error)
{
	ft_putstr_fd("ERROR", 2);
	if (DEBAG)
	{
		ft_putchar_fd('\n', 2);
		ft_putnbr_fd(error, 2);
	}
	ft_putchar_fd('\n', 2);
	exit(1);
}
