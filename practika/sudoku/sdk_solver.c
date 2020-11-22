/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdk_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:38:28 by unite             #+#    #+#             */
/*   Updated: 2019/07/14 18:25:49 by tfelisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdk.h"
#include "ft.h"

int		sdk_pos_ingroup(int pos, int group_id)
{
	if (group_id / 9 == 0)
		return (pos / 9 == group_id % 9);
	if (group_id / 9 == 1)
		return (pos % 9 == group_id % 9);
	else
		return (pos % 9 / 3 == group_id % 9 / 3 &&
				pos / 9 / 3 == group_id % 9 % 3);
}

int		sdk_solnchecker(char *sdk)
{
	int pos;
	int sum;
	int group_id;

	group_id = 0;
	while (group_id < 27)
	{
		pos = 0;
		sum = 0;
		while (pos < 81)
		{
			if (sdk_pos_ingroup(pos, group_id))
				sum += (sdk[pos] - '0');
			pos += 1;
		}
		if (sum != 45)
			return (1);
		group_id += 1;
	}
	return (0);
}

int		sdk_putnum(char *sdk, int pos1, char num)
{
	int pos2;

	pos2 = 0;
	while (pos2 < 81)
	{
		if (pos2 != pos1 && sdk[pos2] == num && sdk_clashed(pos1, pos2))
			return (1);
		pos2 += 1;
	}
	sdk[pos1] = num;
	return (0);
}

int		sdk_nextempty(char *sdk)
{
	int pos;

	pos = 0;
	while (sdk[pos] && sdk[pos] != '.')
		pos += 1;
	return (pos);
}

char	*sdk_solve(char *sdk)
{
	int			pos;
	int			num;
	char		*sdkc;
	static char	*soln = 0;
	static int	nsoln = 0;

	pos = sdk_nextempty(sdk);
	if (pos == 81 && sdk_solnchecker(sdk) == 0)
		soln = (++nsoln <= 1) ? sdk_copy(sdk) : 0;
	else if (nsoln <= 1)
	{
		num = '1';
		sdkc = sdk_copy(sdk);
		while (num <= '9')
		{
			if (sdk_putnum(sdkc, pos, num) == 0)
				sdk_solve(sdkc);
			num += 1;
		}
		free(sdkc);
	}
	return (soln);
}
