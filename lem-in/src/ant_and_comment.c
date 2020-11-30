/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_and_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:08:34 by kplums            #+#    #+#             */
/*   Updated: 2020/11/30 21:08:35 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ants_max_min_bounds(long long num, t_lem *ret, char *line)
{
	if (num <= 0 || num > MAX_INT)
	{
		free(ret->rooms);
		lemin_error(line, LINE_ANT_COUNT);
	}
}

void	ant_count(char *line, t_lem *ret)
{
	int			i;
	long long	num;

	while (get_next_line_gy(0, &line))
	{
		ft_putendl(line);
		if (line[0] == '#')
		{
			if (line[1] == '#')
				lemin_error(line, WRONG_COMMENT);
			free(line);
			continue ;
		}
		i = -1;
		while (line[++i])
			if (line[i] < '0' || line[i] > '9')
				lemin_error(line, LINE_ANT_COUNT);
		num = ft_atoi_longlong(line);
		ants_max_min_bounds(num, ret, line);
		ret->ants_count = num;
		free(line);
		return ;
	}
}

int		sys_or_simple_comm(char *line, t_lem *ret)
{
	if (line[0] == '#')
	{
		if (line[1] == '#')
		{
			free(ret->rooms);
			lemin_error(line, WRONG_COMMENT);
		}
		free(line);
		return (1);
	}
	return (0);
}

int		check_comment(char *line, t_lem *lemin, int *is_soe)
{
	if (ft_strcmp("##start", line) == 0)
	{
		free(line);
		if (lemin->start != -1)
			lemin_error(lemin->rooms, NO_START_OR_END);
		*is_soe = 1;
		return (1);
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		free(line);
		if (lemin->end != -1)
			lemin_error(lemin->rooms, NO_START_OR_END);
		*is_soe = 2;
		return (1);
	}
	return (sys_or_simple_comm(line, lemin));
}
