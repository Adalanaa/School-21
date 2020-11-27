
#include "lem-in.h"

void lemin_error(void *to_free, int error)
{
	if (to_free != NULL)
		free(to_free);
	ft_exit_error(error);
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
