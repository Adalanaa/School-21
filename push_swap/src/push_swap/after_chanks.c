/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_chanks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:48:43 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 21:48:48 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_chank(int tp_head, int tp_tail)
{
	if (tp_head > 0)
		return (1);
	else if (tp_tail > 0)
		return (2);
	else
		return (0);
}

void	bestway_a(t_stacks *stacks, t_save *save, int *chank, int ch_ost)
{
	t_lst_stk	*tp_head;
	t_lst_stk	*tp_tail;

	save->flag_a = 0;
	save->data[2] = -1;
	save->data[3] = 0;
	tp_head = stacks->a->head;
	tp_tail = stacks->a->tail;
	while (tp_head && tp_tail && ++save->data[2] >= 0 && --save->data[3] < 0)
	{
		save->data[4] = check_chank(ft_int_arr_check(chank, save->len /
		save->ch_qty + ch_ost, tp_head->data), ft_int_arr_check(chank, \
		save->len / save->ch_qty + ch_ost, tp_tail->data));
		if (save->data[4])
		{
			save->data[4] == 1 ? (save->flag_a = save->data[2]) : \
			(save->flag_a = save->data[3]);
			save->data[4] == 1 ? (save->num = tp_head->data) : \
			(save->num = tp_tail->data);
			break ;
		}
		tp_head = tp_head->next;
		tp_tail = tp_tail->prev;
	}
	after_chank_b(stacks, save);
}

void	stk_last_chnk(t_stacks *stacks, t_save *save)
{
	int			min;
	t_lst_stk	*tp_head;
	t_lst_stk	*tp_tail;

	min = ft_int_arr_min(arr_stk(stacks->a), stacks->a->size);
	tp_head = stacks->a->head;
	tp_tail = stacks->a->tail;
	while (tp_head && tp_tail)
	{
		if (ft_int_arr_check(&min, 1, tp_head->data))
		{
			while (tp_head != stacks->a->head)
				ra(stacks, save);
			break ;
		}
		else if (ft_int_arr_check(&min, 1, tp_tail->data))
		{
			while (tp_tail != stacks->a->head)
				rra(stacks, save);
			break ;
		}
		tp_head = tp_head->next;
		tp_tail = tp_tail->prev;
	}
	pb(stacks, save);
}

void	stk_after_chnk(t_stacks *stacks, t_save *save)
{
	int	i;
	int	j;
	int	ch_ost;

	i = 1;
	j = 1;
	ch_ost = save->len % save->ch_qty;
	while (i < save->ch_qty)
	{
		if (j <= ch_ost)
			while (stacks->b->size < i * (save->len / save->ch_qty) + j)
				bestway_a(stacks, save, save->chanks[i - 1], 1);
		else
			while (stacks->b->size < i * (save->len / save->ch_qty) + ch_ost)
				bestway_a(stacks, save, save->chanks[i - 1], 0);
		i++;
		j++;
	}
	while (stacks->b->tail->data > stacks->b->head->data)
		rrb(stacks, save);
	while (stacks->a->size > 3)
		stk_last_chnk(stacks, save);
	push_swap_3(stacks, save);
}
