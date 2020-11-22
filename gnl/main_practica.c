/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:58:53 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

typedef struct get_next_line
{
	int						i;
	char 					*line;
	struct get_next_line	*next;
}	GNL;

int	main(void)
{
	int fd;
	int i;
	char *line;
	GNL	*head;
	GNL	*tmp;

	fd = open("/Users/kplums/school/gnl/text.txt", O_RDONLY);
	i = 0;
	head = (GNL *)malloc(sizeof(GNL));
	tmp = head;
	while (get_next_line(fd, &line))
	{
		tmp->next = (GNL *)malloc(sizeof(GNL));
		tmp->i = i++;
		tmp->line = line;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp = head;
	while (tmp->next)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
	return (0);
}