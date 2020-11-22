/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_100_500.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:00:36 by kplums            #+#    #+#             */
/*   Updated: 2020/11/11 22:00:37 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chnk_build(t_save *save, int n)
{
	int	i;
	int	j;
	int	ch_size;
	int flag;

	if (!save->dig_arr || !save->ch_qty || !save->len)
		return ;
	n = 0;
	i = -1;
	save->chanks = (int **)ft_malloc(save->ch_qty, sizeof(int *));
	ch_size = save->len / save->ch_qty;
	while (++i < save->ch_qty)
	{
		flag = 0;
		j = -1;
		if (i < save->len % save->ch_qty)
			flag = 1;
		save->chanks[i] = (int *)ft_malloc(ch_size + flag, sizeof(int));
		while (++j < ch_size + flag)
			save->chanks[i][j] = save->dig_arr[n++];
	}
}

void	chnk_print(int **chanks, int ch_qty, int arr_size)
{
	int i;
	int j;
	int ch_size;

	if (!chanks || !*chanks || !ch_qty || !arr_size)
		return ;
	i = 0;
	ch_size = arr_size / ch_qty;
	while (i < arr_size % ch_qty)
	{
		j = -1;
		while (++j < ch_size + 1)
			ft_printf(" %d", chanks[i][j]);
		ft_printf("\n");
		i++;
	}
	while (i < ch_qty)
	{
		j = -1;
		while (++j < ch_size)
			ft_printf(" %d", chanks[i][j]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	push_swap_100(t_stacks *stacks, t_save *save)
{
	save->ch_qty = 5;
	ft_memdel((void **)&save->dig_arr);
	save->dig_arr = int_arr_sort(stacks->a);
	chnk_build(save, 0);
	stk_after_chnk(stacks, save);
}

void	push_swap_500(t_stacks *stacks, t_save *save)
{
	save->ch_qty = 11;
	ft_memdel((void **)&save->dig_arr);
	save->dig_arr = int_arr_sort(stacks->a);
	chnk_build(save, 0);
	stk_after_chnk(stacks, save);
}
