/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:09:17 by kplums            #+#    #+#             */
/*   Updated: 2020/11/30 21:09:19 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	edit_links(t_lem *lemin, int i, int room)
{
	int j;

	j = 0;
	while (j != lemin->room_count)
	{
		if (lemin->links[i][j] == 1 && j != room &&
			lemin->rooms[i].level > lemin->rooms[j].level && j != lemin->end)
		{
			lemin->links[i][j] = 0;
			lemin->links[j][i] = 0;
			lemin->rooms[j].out--;
			lemin->rooms[i].in--;
		}
		j++;
	}
}

void	delete_in(t_lem *lemin, int i)
{
	int max;
	int room;
	int j;

	j = 0;
	max = 2147483647;
	while (j != lemin->room_count)
	{
		if (lemin->links[i][j] == 1 &&
			lemin->rooms[i].level > lemin->rooms[j].level &&
			max > lemin->rooms[j].out && j != lemin->end)
		{
			max = lemin->rooms[j].out;
			room = j;
		}
		j++;
	}
	edit_links(lemin, i, room);
}

void	check_in(t_lem *lemin)
{
	int i;

	i = 0;
	while (i != lemin->room_count)
	{
		if (lemin->rooms[i].in > 1 && i != lemin->end)
			delete_in(lemin, i);
		i++;
	}
}
