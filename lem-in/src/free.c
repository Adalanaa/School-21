
#include "lem-in.h"

void	coords_free_and_error(t_lem *lemin, char **split, char *line)
{
	ft_memdel((void **)&lemin->rooms);
	free_split(split);
	lemin_error(line, WRONG_ROOM);
}

void	free_split(char **split)
{
	int i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
		split[i] = NULL;
	}
	ft_memdel((void **)&split);
}

void	free_all(t_lem lemin)
{
	int i;

	i = 0;
	while (i < lemin.room_count)
		free(lemin.links[i++]);
	free(lemin.links);
	free(lemin.rooms);
}

void	free_paths(t_path *paths)
{
	t_cont *to_free_cont;
	t_path *to_free_path;

	while (paths != NULL)
	{
		while (paths->path != NULL)
		{
			to_free_cont = paths->path;
			paths->path = paths->path->next;
			free(to_free_cont);
		}
		to_free_path = paths;
		paths = paths->next;
		free(to_free_path);
	}
}
