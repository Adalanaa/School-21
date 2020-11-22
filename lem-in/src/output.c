
#include "lem-in.h"

void	error_case(void *to_free)
{
	if (to_free != NULL)
		free(to_free);
	write(2, "Error\n", 6);
	exit(0);
}

void	print_line(char *line)
{
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
}

void	print_ant_step(char *ant, char *room)
{
	int		ant_len;
	int		room_len;

	ant_len = ft_strlen(ant);
	room_len = ft_strlen(room);
	write(1, "L", 1);
	write(1, ant, ant_len);
	write(1, "-", 1);
	write(1, room, room_len);
	write(1, " ", 1);
	free(ant);
}
