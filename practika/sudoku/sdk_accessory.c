/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdk_accessory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:38:36 by unite             #+#    #+#             */
/*   Updated: 2019/07/14 17:41:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdk.h"
#include "ft.h"

int		sdk_check(char *sdk)
{
	while (*sdk)
	{
		if ((*sdk < '1' || *sdk > '9') && *sdk != '.')
			return (1);
		sdk += 1;
	}
	return (0);
}

char	*sdk_unroll(int argc, char **argv)
{
	char	*sdk;
	int		i;

	sdk = (char *)malloc(sizeof(char) * 82);
	sdk[0] = '\0';
	i = 0;
	if (argc != 10)
		return (0);
	argv += 1;
	while (i < 9)
	{
		if (ft_strlen(argv[i]) != 9)
			return (0);
		sdk = ft_strcat(sdk, argv[i]);
		i += 1;
	}
	if (sdk_check(sdk))
		return (0);
	return (sdk);
}

char	*sdk_copy(char *sdk)
{
	char	*sdkc;
	int		i;

	sdkc = (char *)malloc(sizeof(char) * 82);
	i = 0;
	while (i < 81)
	{
		sdkc[i] = sdk[i];
		i += 1;
	}
	sdkc[i] = '\0';
	return (sdkc);
}

int		sdk_clashed(int pos1, int pos2)
{
	if (pos1 / 9 == pos2 / 9)
		return (1);
	if (pos1 % 9 == pos2 % 9)
		return (1);
	if (pos1 / 9 / 3 == pos2 / 9 / 3)
		if (pos1 % 9 / 3 == pos2 % 9 / 3)
			return (1);
	return (0);
}

void	sdk_print(char *sdk)
{
	int		pos;
	char	separator;

	pos = 0;
	while (pos < 81)
	{
		ft_putchar(sdk[pos]);
		separator = (pos % 9 == 8) ? '\n' : ' ';
		ft_putchar(separator);
		pos += 1;
	}
}
