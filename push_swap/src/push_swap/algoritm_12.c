/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_12.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:53:37 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 13:53:39 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_mediana(t_stk *stack, t_save *save)
{
	int *arr;

	arr = int_arr_sort(stack);
	save->mediana = arr[stack->size / 2];
	ft_memdel((void **)&arr);
}

int		stk_bst_way_less_median(t_stk stack, int mediana)
{
	int			i;
	int			j;
	t_lst_stk	*tmp;

	i = 0;
	j = 0;
	tmp = stack.head;
	while (tmp && tmp->data >= mediana)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = stack.tail;
	while (tmp && tmp->data >= mediana)
	{
		tmp = tmp->prev;
		j++;
	}
	return (i <= j + 1);
}

void	stk_after_mediana_a(t_stacks *stacks, t_save *save)
{
	int size_tmp;

	size_tmp = stacks->b->size + stacks->a->size / 2;
	stk_mediana(stacks->a, save);
	while (stacks->b->size < size_tmp)
	{
		if (stk_bst_way_less_median(*(stacks->a), save->mediana))
		{
			while (stacks->a->head->data >= save->mediana)
				ra(stacks, save);
			pb(stacks, save);
		}
		else
		{
			while (stacks->a->tail->data >= save->mediana)
				rra(stacks, save);
			rra(stacks, save);
			pb(stacks, save);
		}
	}
}

void	stk_after_mediana_b(t_stacks *stacks, t_save *save)
{
	int size_tmp;

	size_tmp = stacks->a->size + 2;
	stk_mediana(stacks->b, save);
	while (stacks->a->size < size_tmp && stacks->b->size > 3)
	{
		if (stacks->b->head->data <= save->mediana)
			rb(stacks, save);
		else
			pa(stacks, save);
	}
	if (stacks->a->head->data > stacks->a->head->next->data)
		sa(stacks, save);
}

void	push_swap_12(t_stacks *stk, t_save *save)
{
	while (stk->a->size > 3)
		stk_after_mediana_a(stk, save);
	push_swap_3(stk, save);
	while (stk->a->size < 6)
	{
		if (stk->b->head->data < stk->b->head->next->data)
			sb(stk, save);
		pa(stk, save);
		if (stk->a->head->data > stk->a->head->next->data)
			sa(stk, save);
	}
	while (stk->b->size > 0)
	{
		if (stk->b->tail->data == ft_int_arr_max(arr_stk(stk->b), stk->b->size))
			rrb(stk, save);
		while (stk->b->head->data == \
		ft_int_arr_max(arr_stk(stk->b), stk->b->size))
			pa(stk, save);
		if (stk->b->head->data == ft_int_arr_min(arr_stk(stk->b), stk->b->size))
			rb(stk, save);
		stk_after_mediana_b(stk, save);
		if (stk->b->head->data < stk->b->head->next->data)
			sb(stk, save);
	}
}
