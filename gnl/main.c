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
#include <string.h>

#include "get_next_line.h"
#include <time.h>
#include <stdio.h>

int sravnenie (int a, int b);

int	main(void)
{
//
//		int		fd;
//		char	*line;
//		double	time_spent;
//		clock_t	begin;
//		clock_t	end;
//
//		begin = clock();
//		fd = open("War and Peace (Lev Tolstoy).txt", O_RDONLY);
//		while (get_next_line(fd, &line) == 1)
//		{
//			ft_putendl(line);
//			free(line);
//		}
//		close(fd);
//		end = clock();
//		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//		printf("Elapsed: %f seconds\n", time_spent);
	int fd;
	int fd1;
	int fd2;
	char *line;
	int i;

	fd = open("/Users/kplums/school/gnl/text.txt", O_RDONLY);
//	while (get_next_line(fd, &line))
//	{
//		printf("%s/n", line);
//		free(line);
//	}
//	free(line);
	fd1 = open("/Users/kplums/school/gnl/text1.txt", O_RDONLY);
	fd2 = open("/Users/kplums/school/gnl/text2.txt", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) && i < 1)
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
		i++;
	}
	while (get_next_line(fd1, &line) && i < 2)
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
		i++;
	}
	while (get_next_line(fd2, &line) && i < 3)
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
		i++;
	}
	while (get_next_line(fd, &line) && i < 4)
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
		i++;
	}
	while (get_next_line(fd1, &line) && i < 5)
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
		i++;
	}
	while (get_next_line(fd2, &line) && i < 6)
	{
		printf("%s\n", line);
		ft_memdel((void **)&line);
		i++;
	}

	while (get_next_line(fd, &line))
	{
		printf("%s|", line);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	close(fd);
//	sravnenie(get_next_line(-99, NULL),-1);
//	sravnenie(get_next_line(-1, NULL),-1);
//	sravnenie(get_next_line(-10000, NULL),-1);
//	sravnenie(get_next_line(1, NULL),-1);
//	sravnenie(get_next_line(99, NULL),-1);
//	sravnenie(get_next_line(-99, &line),-1);
//	sravnenie(get_next_line(-1, &line),-1);
//	sravnenie(get_next_line(-10000, &line),-1);

	return (0);
}

int sravnenie(int a, int b)
{
	if (a == b)
		printf("ok\n");
	return(0);
}