/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:38:54 by unite             #+#    #+#             */
/*   Updated: 2019/07/14 12:59:36 by tfelisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "sdk.h"

int		main(int argc, char **argv)
{
	char *sdk;

	sdk = sdk_unroll(argc, argv);
	if (!sdk)
	{
		ft_putstr("Error\n");
		return (1);
	}
	sdk = sdk_solve(sdk);
	if (!sdk)
	{
		ft_putstr("Error\n");
		return (1);
	}
	sdk_print(sdk);
	return (0);
}
