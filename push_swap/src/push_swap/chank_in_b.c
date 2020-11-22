/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chank_in_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:34:25 by kplums            #+#    #+#             */
/*   Updated: 2020/11/12 17:34:27 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	step_1(t_stacks *stacks, t_save *save)
{
	if (save->flag_a > 0)
	{
		rr(stacks, save);
		save->flag_a--;
	}
	if (save->flag_a < 0)
	{
		rrr(stacks, save);
		save->flag_a++;
	}
	save->flag_b = stk_bestway_b(stacks, save, 0);
}

void	step_2(t_stacks *stacks, t_save *save)
{
	while (save->flag_a > 0 && save->flag_b > 0)
	{
		rr(stacks, save);
		save->flag_a--;
		save->flag_b--;
	}
	while (save->flag_a < 0 && save->flag_b < 0)
	{
		rrr(stacks, save);
		save->flag_a++;
		save->flag_b++;
	}
}

void	step_3(t_stacks *stacks, t_save *save)
{
	while (save->flag_b > 0)
	{
		rb(stacks, save);
		save->flag_b--;
	}
	while (save->flag_b < 0)
	{
		rrb(stacks, save);
		save->flag_b++;
	}
}

void	stk_chank_in_b(t_stacks *stacks, t_save *save)
{
	save->flag_b = stk_bestway_b(stacks, save, save->flag_a);
	while (ft_abs_min(stacks->b->size, save->flag_a) != 2 && save->flag_b != 0)
		step_1(stacks, save);
	step_2(stacks, save);
	step_3(stacks, save);
}

void	after_chank_b(t_stacks *stks, t_save *save)
{
	if (stks->b->size > 1)
		stk_chank_in_b(stks, save);
	while (save->num != stks->a->head->data)
		if (save->flag_a > 0)
			ra(stks, save);
		else if (save->flag_a < 0)
			rra(stks, save);
	pb(stks, save);
}
