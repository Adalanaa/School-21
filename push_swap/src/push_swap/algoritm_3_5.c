/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_3_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:34:44 by kplums            #+#    #+#             */
/*   Updated: 2020/10/18 14:34:46 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_3(t_stacks *stacks, t_save *save)
{
	t_stk *stack_a;

	stack_a = stacks->a;
	if (stack_a->size == 2)
		if (stack_a->head->data > stack_a->tail->data)
			ra(stacks, save);
	if (stack_a->size == 3 && !(stack_a->head->next->data < stack_a->tail->data\
	&& stack_a->head->data < stack_a->head->next->data))
	{
		if (stack_a->head->data < stack_a->tail->data || \
		(stack_a->head->data > stack_a->tail->data && \
		stack_a->head->next->data > stack_a->tail->data && \
		stack_a->head->data > stack_a->head->next->data))
			sa(stacks, save);
		if (stack_a->head->data > stack_a->head->next->data)
			ra(stacks, save);
		else if (stack_a->head->data < stack_a->head->next->data && \
		stack_a->head->next->data > stack_a->tail->data)
			rra(stacks, save);
	}
}

void	push_swap_5(t_stacks *stacks, t_save *save)
{
	pb(stacks, save);
	pb(stacks, save);
	push_swap_3(stacks, save);
	if (stacks->b->head->data < stacks->b->tail->data)
		rb(stacks, save);
	while (stacks->b->size != 0)
	{
		if (((stacks->b->head->data < stacks->a->head->data) \
		|| (stacks->b->head->data > stacks->a->tail->data)) && \
		stacks->a->head->data < stacks->a->tail->data)
			pa(stacks, save);
		else
		{
			while (stacks->b->head->data > stacks->a->head->data)
				ra(stacks, save);
			while (stacks->b->head->data < stacks->a->tail->data)
				rra(stacks, save);
			pa(stacks, save);
		}
	}
	while (stacks->a->tail->data < stacks->a->head->data)
		rra(stacks, save);
}
