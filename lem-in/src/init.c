/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:09:59 by kplums            #+#    #+#             */
/*   Updated: 2020/11/30 21:10:00 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_lemin(t_lem *lemin, int *is_soe, int *i)
{
	lemin->start = -1;
	lemin->end = -1;
	lemin->room_count = 0;
	lemin->ants_count = 0;
	*is_soe = 0;
	*i = 0;
	lemin->memory = 50;
	lemin->rooms = (t_room*)ft_malloc(50, sizeof(t_room));
}

void	new_elem(int id, t_queue *queue)
{
	queue->last->next = malloc(sizeof(t_cont));
	queue->last->next->id = id;
	queue->last->next->next = NULL;
	queue->last = queue->last->next;
}

t_queue	init_queue(int id)
{
	t_queue ret;

	ret.cont = malloc(sizeof(t_cont));
	ret.cont->id = id;
	ret.cont->next = NULL;
	ret.last = ret.cont;
	return (ret);
}

void	init_path(t_lem lemin, t_path **ret, t_cont **path, int i)
{
	int k;

	k = 0;
	while (k < lemin.room_count)
		lemin.rooms[k++].is_visit = 0;
	lemin.rooms[lemin.start].is_visit = 1;
	lemin.rooms[i].is_visit = 1;
	*ret = malloc(sizeof(t_path));
	*path = malloc(sizeof(t_cont));
	(*path)->id = i;
	(*path)->ant = 0;
	(*path)->next = NULL;
	(*ret)->next = NULL;
	(*path)->prev = NULL;
	(*ret)->path = (*path);
	(*ret)->head = (*path);
}

void	init_node_links(t_cont **path, int k)
{
	(*path)->next = malloc(sizeof(t_cont));
	(*path)->next->id = k;
	(*path)->next->ant = 0;
	(*path)->next->next = NULL;
	(*path)->next->prev = (*path);
	(*path) = (*path)->next;
}
