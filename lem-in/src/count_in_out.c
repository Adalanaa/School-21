/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:09:41 by kplums            #+#    #+#             */
/*   Updated: 2020/11/30 21:09:42 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_tupik(t_lem *lemin, int i)
{
	int j;

	j = 0;
	if (i == lemin->end)
		return ;
	if (lemin->rooms[i].out == 0)
	{
		while (j < lemin->room_count)
		{
			if (lemin->links[i][j] == 1)
			{
				lemin->links[i][j] = 0;
				lemin->links[j][i] = 0;
				lemin->rooms[j].out--;
				lemin->rooms[i].in--;
				delete_tupik(lemin, j);
			}
			j++;
		}
	}
}

void	balance_in_out(t_lem *lemin, int i, int j)
{
	if (lemin->rooms[i].level < lemin->rooms[j].level)
	{
		lemin->rooms[i].out++;
		lemin->rooms[j].in++;
	}
	else if (lemin->rooms[i].level > lemin->rooms[j].level)
	{
		lemin->rooms[j].out++;
		lemin->rooms[i].in++;
	}
}

void	dfs_in_out(t_lem *lemin)
{
	int i;
	int j;

	i = 0;
	while (i < lemin->room_count)
	{
		j = i;
		while (j < lemin->room_count)
		{
			if (lemin->rooms[i].level == lemin->rooms[j].level
				&& lemin->links[i][j] == 1)
			{
				lemin->links[i][j] = 0;
				lemin->links[j][i] = 0;
			}
			if (lemin->links[i][j] == 1)
				balance_in_out(lemin, i, j);
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < lemin->room_count)
		delete_tupik(lemin, i);
}

void	count_in_out(t_lem *lemin)
{
	int i;

	i = 0;
	while (i < lemin->room_count)
	{
		lemin->rooms[i].in = 0;
		lemin->rooms[i].out = 0;
		i++;
	}
	dfs_in_out(lemin);
}
