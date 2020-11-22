/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:30:05 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 18:30:07 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*arr_stk(t_stk *stack)
{
	int			i;
	int			*num_arr;
	t_lst_stk	*tmp;

	i = 0;
	if (stack->size == 0)
		return (NULL);
	tmp = stack->head;
	num_arr = (int *)ft_malloc(stack->size, sizeof(int));
	while (tmp)
	{
		num_arr[i++] = tmp->data;
		tmp = tmp->next;
	}
	return (num_arr);
}

int		*int_arr_sort(t_stk *stack)
{
	int	i;
	int	tmp;
	int	*arr;

	i = 0;
	arr = arr_stk(stack);
	while (i != stack->size - 1)
	{
		while (i + 1 < stack->size)
		{
			while (arr[i] < arr[i + 1] && i + 1 < stack->size)
				i++;
			if (i + 1 < stack->size)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				i = 0;
			}
		}
	}
	return (arr);
}

void	chnk_free(int **chanks, int ch_count)
{
	int i;

	if (!chanks || !*chanks || !ch_count)
		return ;
	i = -1;
	while (++i < ch_count)
		ft_memdel((void **)&(chanks[i]));
	free(chanks);
	chanks = NULL;
}

void	parser_sort_stack(t_stacks *stacks, t_save *save)
{
	t_lst_stk *tmp_a;
	t_lst_stk *tmp_b;

	tmp_a = stacks->a->head;
	tmp_b = stacks->b->head;
	while (tmp_b && tmp_b->next && tmp_b->data > tmp_b->next->data)
		tmp_b = tmp_b->next;
	while (tmp_a && tmp_a->next && tmp_a->data < tmp_a->next->data)
		tmp_a = tmp_a->next;
	if (tmp_b != NULL && tmp_a == stacks->a->tail && tmp_b == stacks->b->tail \
	&& stacks->a->head->data > stacks->b->head->data && save->flag_checker == 0)
		while (stacks->b->size != 0)
			pa(stacks, save);
	if (stacks->b->size == 0 && tmp_a == stacks->a->tail &&
		save->flag_checker == 0)
	{
		chnk_free(save->chanks, save->ch_qty);
		ft_memdel((void **)&save->dig_arr);
		exit(0);
	}
}
