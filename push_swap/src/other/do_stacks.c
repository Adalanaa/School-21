/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:28:25 by kplums            #+#    #+#             */
/*   Updated: 2020/10/01 15:28:28 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushtail_stack(t_stk *stack, int data)
{
	t_lst_stk	*tmp;

	tmp = (t_lst_stk *)ft_malloc(1, sizeof(t_lst_stk));
	tmp->data = data;
	if (stack->head == NULL)
	{
		stack->head = tmp;
		stack->tail = tmp;
		stack->head->prev = NULL;
		stack->tail->next = NULL;
	}
	else
	{
		(stack)->tail->next = tmp;
		tmp->prev = (stack)->tail;
	}
	(stack)->tail = tmp;
	tmp->next = NULL;
	(stack)->size++;
}

void	pushhead_stack(t_stk *stack, t_lst_stk *tmp)
{
	tmp->next = (stack)->head;
	tmp->prev = NULL;
	if ((stack)->head)
		(stack)->head->prev = tmp;
	(stack)->head = tmp;
	if ((stack)->tail == NULL)
		(stack)->tail = tmp;
	(stack)->size++;
}

void	print_stack(t_stk *stack_a, t_stk *stack_b, int null_a, int null_b)
{
	t_lst_stk	*tmp_a;
	t_lst_stk	*tmp_b;

	null_a = ft_int_max((int)stack_a->size, (int)stack_b->size) - stack_a->size;
	null_b = ft_int_max((int)stack_a->size, (int)stack_b->size) - stack_b->size;
	tmp_a = stack_a->head;
	tmp_b = stack_b->head;
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (null_a-- > 0)
			ft_printf("%11.d", 0);
		else
		{
			ft_printf("% 11d", tmp_a->data);
			tmp_a = tmp_a->next;
		}
		if (null_b-- > 0)
			ft_printf("% 13.d\n", 0);
		else
		{
			ft_printf("% 13d\n", tmp_b->data);
			tmp_b = tmp_b->next;
		}
	}
	ft_printf("-----------%13s\n%11c%13c\n", "-----------", 'a', 'b');
}

t_stk	*ft_init_stacks(void)
{
	t_stk *stack;

	stack = (t_stk *)ft_malloc(1, sizeof(t_stk));
	if (stack == NULL)
		ft_exit_error(103);
	(stack)->size = 0;
	(stack)->head = NULL;
	(stack)->tail = (stack)->head;
	return (stack);
}

void	build_stacks(int *arr_st, t_stacks *stacks, t_save *save)
{
	stacks->a = ft_init_stacks();
	stacks->b = ft_init_stacks();
	while (stacks->a->size < save->len)
		pushtail_stack(stacks->a, arr_st[(stacks->a)->size]);
	if (save->flag_v == 1)
	{
		ft_printf("Init a and b:\n");
		print_stack(stacks->a, stacks->b, 0, 0);
	}
}
