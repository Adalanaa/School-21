/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:29:54 by kplums            #+#    #+#             */
/*   Updated: 2020/11/04 21:29:57 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks *stacks, t_save *save)
{
	if (stacks->a->size < 4)
		push_swap_3(stacks, save);
	else if (stacks->a->size < 6)
		push_swap_5(stacks, save);
	else if (stacks->a->size < 13)
		push_swap_12(stacks, save);
	else if (stacks->a->size < 101)
		push_swap_100(stacks, save);
	else
		push_swap_500(stacks, save);
}

int		main(int ac, char **argv)
{
	t_save		save;
	t_stacks	stacks;

	if (ac < 2)
		ft_exit_error(AC);
	ft_bzero(&stacks, sizeof(stacks));
	ft_bzero(&save, sizeof(save));
	save.flag_checker = 0;
	push_swap_parser(ac, &save, argv, NULL);
	build_stacks(save.dig_arr, &stacks, &save);
	push_swap(&stacks, &save);
	exit(0);
}
