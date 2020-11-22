/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:55:12 by kplums            #+#    #+#             */
/*   Updated: 2020/09/25 15:55:14 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks, t_save *save)
{
	t_lst_stk	*tmp;

	if (stacks->b->head)
	{
		tmp = stacks->b->head;
		stacks->b->head = stacks->b->head->next;
		if (stacks->b->head == NULL)
			stacks->b->tail = NULL;
		if (stacks->b->head && stacks->b->head->prev)
			stacks->b->head->prev = NULL;
		stacks->b->size--;
		tmp->prev = NULL;
		tmp->next = NULL;
		pushhead_stack(stacks->a, tmp);
	}
	if (save->flag_checker == 0)
		ft_printf("pa\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}

void	pb(t_stacks *stacks, t_save *save)
{
	t_lst_stk	*tmp;

	if (stacks->a->head)
	{
		tmp = stacks->a->head;
		stacks->a->head = stacks->a->head->next;
		if (stacks->a->head == NULL)
			stacks->a->tail = NULL;
		if (stacks->a->head)
			stacks->a->head->prev = NULL;
		stacks->a->size--;
		tmp->prev = NULL;
		tmp->next = NULL;
		pushhead_stack(stacks->b, tmp);
	}
	if (save->flag_checker == 0)
		ft_printf("pb\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}
