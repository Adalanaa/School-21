/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:31:54 by kplums            #+#    #+#             */
/*   Updated: 2020/01/07 17:31:56 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
int ft_putstr(char *string)
{
	while (*string)
	{
		ft_putchar(*string);
		string++;
	}

	return (0);
}

int ft_strlen(char *string)
{
	int i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (av[i][0] != 40 && av[i][0] != 123 && av[i][0] != 91)
			{
				ft_putstr("OK\n");
			}
			else
			{
				if (av[i][0] == 40)
				{
					if (av[i][ft_strlen(av[i]) - 1] == 41)
						ft_putstr("OK\n");
					else
						ft_putstr("Error\n");
				}
				if (av[i][0] == 123)
				{
					if (av[i][ft_strlen(av[i]) - 1] == 125)
						ft_putstr("OK\n");
					else
						ft_putstr("Error\n");
				}
				if (av[i][0] == 91)
				{
					if (av[i][ft_strlen(av[i]) - 1] == 93)
						ft_putstr("OK\n");
					else
						ft_putstr("Error\n");
				}
			}
			i++;
		}
	}
	else
		ft_putstr("\n");
	return 0;
}
