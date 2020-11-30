/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:10:18 by kplums            #+#    #+#             */
/*   Updated: 2020/11/30 21:10:19 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_links(int *link1, int *link2, t_lem *ret, char **split)
{
	int len;
	int count;

	len = -1;
	*link1 = 0;
	*link2 = 0;
	count = 0;
	while (++len != ret->room_count)
	{
		if (ft_strcmp(ret->rooms[len].name, split[0]) == 0 ||
			ft_strcmp(ret->rooms[len].name, split[1]) == 0)
		{
			*link1 = ft_strcmp(ret->rooms[len].name, split[0]) == 0 \
														? len : *link1;
			*link2 = ft_strcmp(ret->rooms[len].name, split[1]) == 0 \
														? len : *link2;
			count++;
		}
	}
	return (count);
}

int		is_link(int link1, int link2, t_lem *ret, int count)
{
	if (count != 2)
	{
		free(ret->rooms);
		return (0);
	}
	else
	{
		ret->links[link1][link2] = 1;
		ret->links[link2][link1] = 1;
		return (1);
	}
}

void	add_links(char *line, t_lem *lemin)
{
	char	**split;
	int		len;
	int		count;
	int		link1;
	int		link2;

	len = -1;
	split = ft_strsplit(line, '-');
	while (split[++len])
		;
	if (len != 2)
	{
		free_split(split);
		free(lemin->rooms);
		lemin_error(line, WRONG_LINK);
	}
	count = check_links(&link1, &link2, lemin, split);
	free_split(split);
	if (!is_link(link1, link2, lemin, count))
		lemin_error(line, WRONG_LINK);
}

void	create_array_links(t_lem *ret)
{
	int i;
	int j;

	i = 0;
	ret->links = (int **)malloc(sizeof(int *) * (ret->room_count));
	while (i != ret->room_count)
	{
		j = 0;
		ret->links[i] = (int *)malloc(sizeof(int) * (ret->room_count));
		while (j != ret->room_count)
		{
			ret->links[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_lem	array_links(t_lem lemin, int is_soe, int answer, char *line)
{
	if (lemin.start == -1 || lemin.end == -1 || answer == 0)
		lemin_error(lemin.rooms, WRONG_ROOM);
	create_array_links(&lemin);
	while (1)
	{
		if (check_comment(line, &lemin, &is_soe))
		{
			if (get_next_line_gy(0, &line) <= 0)
				break ;
			print_line(line);
			continue ;
		}
		add_links(line, &lemin);
		free(line);
		if (get_next_line_gy(0, &line) <= 0)
			break ;
		print_line(line);
	}
	write(1, "\n", 1);
	return (lemin);
}
