/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:58:41 by kplums            #+#    #+#             */
/*   Updated: 2020/11/04 17:58:43 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker_line(char *tmp)
{
	if (ft_strcmp(tmp, "ra") == 0)
		return (1);
	else if (ft_strcmp(tmp, "rb") == 0)
		return (1);
	else if (ft_strcmp(tmp, "rr") == 0)
		return (1);
	else if (ft_strcmp(tmp, "sa") == 0)
		return (1);
	else if (ft_strcmp(tmp, "sb") == 0)
		return (1);
	else if (ft_strcmp(tmp, "ss") == 0)
		return (1);
	else if (ft_strcmp(tmp, "pa") == 0)
		return (1);
	else if (ft_strcmp(tmp, "pb") == 0)
		return (1);
	else if (ft_strcmp(tmp, "rra") == 0)
		return (1);
	else if (ft_strcmp(tmp, "rrb") == 0)
		return (1);
	else if (ft_strcmp(tmp, "rrr") == 0)
		return (1);
	else
		return (0);
}

void	checker_doit(char *tmp, t_stacks *stacks, t_save *save)
{
	if (ft_strcmp(tmp, "ra") == 0)
		ra(stacks, save);
	else if (ft_strcmp(tmp, "rb") == 0)
		rb(stacks, save);
	else if (ft_strcmp(tmp, "rr") == 0)
		rr(stacks, save);
	else if (ft_strcmp(tmp, "sa") == 0)
		sa(stacks, save);
	else if (ft_strcmp(tmp, "sb") == 0)
		sb(stacks, save);
	else if (ft_strcmp(tmp, "ss") == 0)
		ss(stacks, save);
	else if (ft_strcmp(tmp, "pa") == 0)
		pa(stacks, save);
	else if (ft_strcmp(tmp, "pb") == 0)
		pb(stacks, save);
	else if (ft_strcmp(tmp, "rra") == 0)
		rra(stacks, save);
	else if (ft_strcmp(tmp, "rrb") == 0)
		rrb(stacks, save);
	else if (ft_strcmp(tmp, "rrr") == 0)
		rrr(stacks, save);
}

void	checker_sort_stacks(t_stacks *stacks)
{
	t_lst_stk *tmp_a;

	tmp_a = stacks->a->head;
	while (tmp_a && tmp_a->next && tmp_a->data < tmp_a->next->data)
		tmp_a = tmp_a->next;
	if (tmp_a == stacks->a->tail && stacks->b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	push_swap_checker(t_stacks *stacks, t_save *save)
{
	int		i;
	char	c;
	char	tmp[4];

	i = 0;
	ft_bzero(tmp, 4);
	while (read(0, &c, 1) == 1)
	{
		if (c != '\n' && c != '\0')
		{
			if (i == 3)
				ft_exit_error(110);
			tmp[i++] = c;
		}
		else
		{
			if (checker_line(tmp) == 1)
				checker_doit(tmp, stacks, save);
			else
				ft_exit_error(110);
			ft_bzero(tmp, 4);
			i = 0;
		}
	}
	checker_sort_stacks(stacks);
}

int		main(int ac, char **argv)
{
	t_save		save;
	t_stacks	stacks;

	if (ac < 2)
		exit(101);
	ft_bzero(&stacks, sizeof(stacks));
	ft_bzero(&save, sizeof(save));
	save.flag_checker = 1;
	push_swap_parser(ac, &save, argv, NULL);
	build_stacks(save.dig_arr, &stacks, &save);
	push_swap_checker(&stacks, &save);
	exit(0);
}
