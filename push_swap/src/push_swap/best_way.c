/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:07:37 by kplums            #+#    #+#             */
/*   Updated: 2020/11/12 14:07:38 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	beatway_max_min(t_stacks *stacks, t_lst_stk *tp, t_lst_stk *tp_next, \
						int *data)
{
	data[0] = 1;
	data[1] = -1;
	if (stacks->b->head->data < stacks->b->tail->data)
	{
		while (tp_next && tp->data > tp_next->data)
		{
			tp = tp_next;
			tp_next = tp_next->next;
			data[0]++;
		}
		tp = stacks->b->tail->prev;
		tp_next = stacks->b->tail;
		while (tp && tp->data > tp_next->data)
		{
			tp_next = tp;
			tp = tp->prev;
			data[1]--;
		}
	}
}

void	bestway_other(t_stacks *stacks, t_save *save, t_lst_stk *tp,
		t_lst_stk *tp_next)
{
	save->data[0] = 1;
	save->data[1] = -1;
	if (!(save->num > stacks->b->head->data && \
		save->num < stacks->b->tail->data))
	{
		while (tp_next && !(save->num > tp_next->data && save->num < tp->data))
		{
			tp = tp_next;
			tp_next = tp_next->next;
			save->data[0]++;
		}
		tp = stacks->b->tail->prev;
		tp_next = stacks->b->tail;
		while (tp && !(save->num > tp_next->data && save->num < tp->data))
		{
			tp_next = tp;
			tp = tp->prev;
			save->data[1]--;
		}
	}
}

int		check_data(t_save *save, int flag_a)
{
	if (ft_abs_min(save->data[0], save->data[1]) == 1)
		return (save->data[0]);
	else if (ft_abs_min(save->data[0], save->data[1]) == 2)
		return (save->data[1]);
	else if (flag_a != 0)
		return (save->data[0] * (flag_a > 0 ? 1 : -1));
	else
		return (save->data[0]);
}

int		stk_bestway_b(t_stacks *sks, t_save *save, int flag_a)
{
	t_lst_stk *tp;
	t_lst_stk *tp_next;

	tp = sks->b->head;
	tp_next = sks->b->head->next;
	if ((save->num > ft_int_arr_max(arr_stk(sks->b), sks->b->size)) ||
		(save->num < ft_int_arr_min(arr_stk(sks->b), sks->b->size)))
	{
		if (sks->b->head->data < sks->b->tail->data)
			beatway_max_min(sks, tp, tp_next, (int *)&save->data);
		else
			return (0);
	}
	else
	{
		if (!(save->num > sks->b->head->data && save->num < sks->b->tail->data))
			bestway_other(sks, save, tp, tp_next);
		else
			return (0);
	}
	return (check_data(save, flag_a));
}
