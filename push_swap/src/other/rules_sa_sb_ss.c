/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:00:18 by kplums            #+#    #+#             */
/*   Updated: 2020/09/25 15:00:20 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stack(t_stk *stack)
{
	t_lst_stk	*tmp;

	if (stack->size > 1)
	{
		if (stack->size == 2)
		{
			tmp = stack->tail;
			stack->tail = stack->head;
			stack->tail->next = NULL;
			stack->tail->prev = tmp;
			stack->head = tmp;
			stack->head->prev = NULL;
			stack->head->next = stack->tail;
		}
		else
		{
			tmp = stack->head->next;
			stack->head->next = tmp->next;
			stack->head->prev = tmp;
			tmp->next = stack->head;
			tmp->prev = NULL;
			stack->head = tmp;
			stack->head->next->next->prev = stack->head->next;
		}
	}
}

void	sa(t_stacks *stacks, t_save *save)
{
	ft_swap_stack(stacks->a);
	if (save->flag_checker == 0)
		ft_printf("sa\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}

void	sb(t_stacks *stacks, t_save *save)
{
	ft_swap_stack(stacks->b);
	if (save->flag_checker == 0)
		ft_printf("sb\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}

void	ss(t_stacks *stacks, t_save *save)
{
	ft_swap_stack(stacks->a);
	ft_swap_stack(stacks->b);
	if (save->flag_checker == 0)
		ft_printf("ss\n");
	if (save->flag_v == 1)
		print_stack(stacks->a, stacks->b, 0, 0);
	save->step++;
	parser_sort_stack(stacks, save);
}
