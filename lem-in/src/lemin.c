/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:10:12 by kplums            #+#    #+#             */
/*   Updated: 2020/11/30 21:10:13 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_level_room(t_lem *lemin)
{
	t_arr array_1;
	t_arr array_2;

	lemin->rooms[lemin->start].level = 0;
	lemin->rooms[lemin->end].level = MAX_INT;
	array_1.len = 0;
	array_2.len = 0;
	array_1.array = create_first_array(lemin, &array_1.len);
	while (1)
	{
		array_2.array = create_array(array_1.array, \
		lemin, array_1.len, &array_2.len);
		ft_memdel((void **)&array_1.array);
		if (array_2.len == 0)
			break ;
		array_1.array = create_array(array_2.array, \
		lemin, array_2.len, &array_1.len);
		ft_memdel((void **)&array_2.array);
		if (array_1.len == 0)
			break ;
	}
}

int		main(void)
{
	t_lem	lemin;
	int		i;

	i = 0;
	lemin = lemin_parser();
	add_level_room(&lemin);
	count_in_out(&lemin);
	check_in(&lemin);
	check_out(&lemin);
	while (i < lemin.room_count)
	{
		delete_tupik(&lemin, i);
		i++;
	}
	if (lemin.rooms[lemin.start].out == 0)
	{
		free_all(lemin);
		lemin_error(NULL, WRONG_MAP);
	}
	lemin.paths = get_paths(lemin);
	move_ants(lemin);
	free_paths(lemin.paths);
	free_all(lemin);
	return (0);
}
