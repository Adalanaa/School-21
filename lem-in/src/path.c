/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:11:19 by kplums            #+#    #+#             */
/*   Updated: 2020/11/30 21:11:21 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*create_path(int i, t_lem lemin)
{
	t_path	*ret;
	t_cont	*path;
	int		k;

	init_path(lemin, &ret, &path, i);
	while (path->id != lemin.end)
	{
		k = 0;
		while (1)
		{
			if (lemin.links[i][k] == 1 && lemin.rooms[k].is_visit == 0)
			{
				init_node_links(&path, k);
				ret->size++;
				lemin.rooms[k].is_visit = 1;
				i = k;
				break ;
			}
			k++;
		}
	}
	ret->last = path;
	return (ret);
}

void	find_position(t_path *ret, t_path *cur)
{
	t_path *buf;
	t_path *tmp;

	buf = ret;
	while (buf->next != NULL)
	{
		if (cur->size >= buf->size && cur->size <= buf->next->size)
		{
			tmp = buf->next;
			buf->next = cur;
			cur->next = tmp;
			break ;
		}
		buf = buf->next;
	}
}

void	first_three_paths(t_path **last, t_path **ret, t_path *cur)
{
	if (*ret == NULL)
	{
		*ret = cur;
		*last = cur;
	}
	else if (cur->size <= (*ret)->size)
	{
		cur->next = *ret;
		*ret = cur;
	}
	else if (cur->size >= (*last)->size)
	{
		(*last)->next = cur;
		*last = (*last)->next;
	}
}

t_path	*get_paths(t_lem lemin)
{
	t_path	*last;
	t_path	*head;
	t_path	*tmp;
	int		i;

	head = NULL;
	i = 0;
	while (i < lemin.room_count)
	{
		if (lemin.links[lemin.start][i] == 1)
		{
			tmp = create_path(i, lemin);
			if (head == NULL || tmp->size <= head->size ||
				tmp->size >= last->size)
				first_three_paths(&last, &head, tmp);
			else
				find_position(head, tmp);
		}
		i++;
	}
	return (head);
}
