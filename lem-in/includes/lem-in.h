/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:26:28 by kplums            #+#    #+#             */
/*   Updated: 2020/11/15 13:26:30 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft.h"

enum				lemin_errors
{
	LINE_ANT_COUNT	= 201,
	WRONG_COMMENT	= 202,
	NO_START_OR_END	= 203,
	WRONG_ROOM		= 204
};

typedef struct		s_room
{
	char			name[128];
	int				x;
	int				y;
	int				is_start;
	int				is_end;
	int				is_visit;
	int				level;
	int				out;
	int				in;
	int				ant;
}					t_room;

typedef struct		s_cont
{
	int				id;
	int				ant;
	struct s_cont	*next;
	struct s_cont	*prev;
}					t_cont;

typedef struct		s_queue
{
	t_cont			*cont;
	t_cont			*last;
}					t_queue;

typedef struct		s_path
{
	int				size;
	int				ratio;
	t_cont			*path;
	t_cont			*first;
	t_cont			*last;
	struct s_path	*next;
}					t_path;

typedef struct		s_lem
{
	int				start;
	int				end;
	t_room			*rooms;
	int				memory;
	int				**links;
	int				room_count;
	int				ants_count;
	t_path			*paths;
	int				finished;
}					t_lem;

typedef	struct		s_arr
{
	int				*array;
	int				len;
}					t_arr;

typedef struct		s_c
{
	int				i;
	int				j;
	int				k;
	int				z;
	int				check;
	int				count;
}					t_c;

int					*create_first_array(t_lem *lemin, int *len);
int					*create_array(int *array, t_lem *lemin, \
					int len, int *len_new);
t_lem				lemin_parser(void);
void				count_in_out(t_lem *lemin);
void				check_in(t_lem *lemin);
void				check_out(t_lem *lemin);
void				delete_dead_end(t_lem *lemin, int i);
t_path				*get_paths(t_lem lemin);
void				move_ants(t_lem lemin);
void				free_paths(t_path *paths);
void				free_all(t_lem lemin);
void				print_line(char *line);
void				lemin_error(void *to_free, int error);
t_queue				init_queue(int id);
void				new_elem(int id, t_queue *queue);
void				free_split(char **split);
int					check_comment(char *line, t_lem *lemin, int *is_soe);
void				init_node_links(t_cont **path, int k);
void				init_path(t_lem lemin, t_path **ret, t_cont **path, int i);
void				ant_count(char *line, t_lem *ret);
t_lem				array_links(t_lem ret, int is_soe, int answer, char *line);
void				init_lemin(t_lem *ret, int *a, int *i);
void				coords_free_and_error(t_lem *lemin, char **split, char *line);
void				print_ant_step(char *ant, char *room);

/*
** Errors:
** 101 - !dig_arr

*/


#endif
