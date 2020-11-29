
#include "lem-in.h"

void	increase_array(t_lem *ret)
{
	t_room	*copy_array;
	int		i;

	copy_array = (t_room*)malloc(sizeof(t_room) * ret->memory * 2);
	ret->memory *= 2;
	i = 0;
	while (i < ret->room_count)
	{
		copy_array[i] = ret->rooms[i];
		i++;
	}
	free(ret->rooms);
	ret->rooms = copy_array;
}

t_room	get_coords(char **split, char *line, t_lem *lemin, t_room room_ret)
{
	int i;

	i = -1;
	while (split[1][++i])
		if (split[1][i] < '0' || split[1][i] > '9')
			coords_free_and_error(lemin, split, line);
	i = -1;
	while (split[2][++i])
		if (split[2][i] < '0' || split[2][i] > '9')
			coords_free_and_error(lemin, split, line);
	room_ret.x = ft_atoi(split[1]);
	room_ret.y = ft_atoi(split[2]);
	i = -1;
	while (++i < lemin->room_count)
		if (lemin->rooms[i].x == room_ret.x && lemin->rooms[i].y == room_ret.y)
			coords_free_and_error(lemin, split, line);
	return (room_ret);
}

t_room	get_room(char *line, t_lem *lemin)
{
	char	**split;
	int		len;
	t_room	room_ret;

	len = 0;
	room_ret.level = -1;
	split = ft_strsplit(line, ' ');
	while (split[len] != NULL)
		len++;
	if (len != 3)
		coords_free_and_error(lemin, split, line);
	room_ret = get_coords(split, line, lemin, room_ret);
	lemin->room_count++;
	if (split[0][0] == 'L')
		coords_free_and_error(lemin, split, line);
	ft_strcpy(room_ret.name, split[0]);
	free_split(split);
	return (room_ret);
}

t_lem	lemin_parser(void)
{
	char	*line;
	t_lem	lemin;
	int		is_soe;
	int		i;
	int		answer;

	line = NULL;
	init_lemin(&lemin, &is_soe, &i);
	ant_count(line, &lemin);
	while ((answer = get_next_line_bd(0, &line)))
	{
		print_line(line);
		if (check_comment(line, &lemin, &is_soe))
			continue ;
		if (ft_strchr(line, '-') != NULL)
			break ;
		lemin.start = is_soe == 1 ? i : lemin.start;
		lemin.end = is_soe == 2 ? i : lemin.end;
		if (lemin.room_count >= lemin.memory)
			increase_array(&lemin);
		lemin.rooms[i++] = get_room(line, &lemin);
		is_soe = -1;
		free(line);
	}

	return (array_links(lemin, is_soe, answer, line));
}
