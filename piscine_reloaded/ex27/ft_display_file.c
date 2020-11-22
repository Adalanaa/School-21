/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:13:29 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int			main(int ac, char **av)
{
	int		fd;
	char	ch;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr2("open() error\n");
			return (1);
		}
		while (read(fd, &ch, 1) > 0)
			ft_putchar(ch);
		if (close(fd) == -1)
		{
			ft_putstr2("close() error\n");
			return (1);
		}
	}
	if (ac < 2)
		ft_putstr2("File name missing.\n");
	if (ac > 2)
		ft_putstr2("Too many arguments.\n");
	return (0);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putchar2(char c)
{
	write(2, &c, 1);
}

void		ft_putstr2(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar2(str[i]);
}
