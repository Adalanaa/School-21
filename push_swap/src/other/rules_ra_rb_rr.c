/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ra_rb_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:31:47 by kplums            #+#    #+#             */
/*   Updated: 2020/09/27 15:31:49 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_stack(t_stk *stack)
{
	t_lst_stk	*tmp;

	if (stack->size > 1)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		tmp->prev = stack->tail;
		tmp->next = NULL;
		stack->tail->next = tmp;
		stack->tail = tmp;
	}
}

void	ra(t_stacks *stacks, t_save *save)
{
	ft_rotate_stack(stacks->a);
	if (save->flag_checker == 0)
		ft_printf("ra\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}

void	rb(t_stacks *stacks, t_save *save)
{
	ft_rotate_stack(stacks->b);
	if (save->flag_checker == 0)
		ft_printf("rb\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}

void	rr(t_stacks *stacks, t_save *save)
{
	ft_rotate_stack(stacks->a);
	ft_rotate_stack(stacks->b);
	if (save->flag_checker == 0)
		ft_printf("rr\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}
