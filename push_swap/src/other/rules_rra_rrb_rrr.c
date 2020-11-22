/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rra_rrb_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:58:28 by kplums            #+#    #+#             */
/*   Updated: 2020/09/27 15:58:29 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_stack(t_stk *stack)
{
	t_lst_stk	*tmp;

	if (stack->size > 1)
	{
		tmp = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		tmp->next = stack->head;
		tmp->prev = NULL;
		stack->head->prev = tmp;
		stack->head = tmp;
	}
}

void	rra(t_stacks *stacks, t_save *save)
{
	ft_reverse_rotate_stack(stacks->a);
	if (save->flag_checker == 0)
		ft_printf("rra\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}

void	rrb(t_stacks *stacks, t_save *save)
{
	ft_reverse_rotate_stack(stacks->b);
	if (save->flag_checker == 0)
		ft_printf("rrb\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}

void	rrr(t_stacks *stacks, t_save *save)
{
	ft_reverse_rotate_stack(stacks->a);
	ft_reverse_rotate_stack(stacks->b);
	if (save->flag_checker == 0)
		ft_printf("rrr\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}
