/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:39:00 by kplums            #+#    #+#             */
/*   Updated: 2020/09/05 18:39:05 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct			s_list_stk
{
	int					data;
	struct s_list_stk	*next;
	struct s_list_stk	*prev;
}						t_lst_stk;

typedef struct			s_dbl_stack
{
	int					size;
	t_lst_stk			*head;
	t_lst_stk			*tail;
}						t_stk;

typedef struct			s_stacks
{
	t_stk				*a;
	t_stk				*b;

}						t_stacks;

typedef struct			s_save
{
	int					flag_count;
	int					flag_v;
	int					flag_checker;
	int					step;
	int					mediana;
	int					len;
	int					ch_qty;
	int					*dig_arr;
	int					**chanks;
	int					flag_a;
	int					flag_b;
	int					num;
	int					data[5];
}						t_save;

void					push_swap_parser(int ac, t_save *save, char **argv, \
						char **num_arr);
void					print_stack(t_stk *stack_a, t_stk *stack_b, \
						int null_a, int null_b);
void					pushtail_stack(t_stk *stack, int data);
void					pushhead_stack(t_stk *stack, t_lst_stk *tmp);
void					parser_sort_stack(t_stacks *stacks, t_save *save);
void					build_stacks(int *arr_st, t_stacks *stacks, \
						t_save *save);
int						*int_arr_sort(t_stk *stack);
int						*arr_stk(t_stk *stack);
int						*int_arr_sort(t_stk *stack);
void					stk_after_chnk(t_stacks *stacks, t_save *save);
void					after_chank_b(t_stacks *stks, t_save *save);
int						stk_bestway_b(t_stacks *sks, t_save *save, int flag_a);

void					push_swap(t_stacks *stacks, t_save *save);
void					push_swap_3(t_stacks *stacks, t_save *save);
void					push_swap_5(t_stacks *stacks, t_save *save);
void					push_swap_12(t_stacks *stk, t_save *save);
void					push_swap_100(t_stacks *stacks, t_save *save);
void					push_swap_500(t_stacks *stacks, t_save *save);

void					sa(t_stacks *stacks, t_save *save);
void					sb(t_stacks *stacks, t_save *save);
void					ss(t_stacks *stacks, t_save *save);
void					pa(t_stacks *stacks, t_save *save);
void					pb(t_stacks *stacks, t_save *save);
void					ra(t_stacks *stacks, t_save *save);
void					rb(t_stacks *stacks, t_save *save);
void					rr(t_stacks *stacks, t_save *save);
void					rra(t_stacks *stacks, t_save *save);
void					rrb(t_stacks *stacks, t_save *save);
void					rrr(t_stacks *stacks, t_save *save);

/*
** Errors:
** 102 - !dig_arr
** 104 - no line in checkline
** 105 - checkline fd
** 106 - checkline arg[1]
** 107 - checkline argv
** 108 - same digital
** 109 - arr was sort
** 110 - checker error *argv
** 111 - MAX or MIN int
*/

#endif
