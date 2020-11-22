/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:45:32 by kplums            #+#    #+#             */
/*   Updated: 2020/01/12 15:45:35 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stdio.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(*str);
		str++;
	}

	return 0;
}

int ft_chechalf(char c, char *str)
{
	int i = 0;
	if(!str || c == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	while (str[--i])
	{
		if (c == str[i])
			return (i);
	}
	return (i);
}

int main(int ac, char **av)
{
	char zero[] = "00000000 00000000 00000000 00000000";
	char *alf;
	int i = 1;
	int j = 1;
	int flag = 0;

	alf  = "******zy xwvutsrq ponmlkji hgfedcba";
	if(ac > 1)
	{
		while (av[i])
		{
			j = 1;
			if (av[i][0] == '-')
            {
                while (av[i][j])
                {
                    if (av[i][j] == 'h')
                    {
                        ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
                        return 0;
                    }
                    if(ft_chechalf(av[i][j], alf) < 6
                            )
                    {
                        ft_putstr("Invalid Option\n");
                        return 0;
                    }
                    zero[ft_chechalf(av[i][j], alf)] = '1';
                    flag = 1;
                    j++;
                }
            }
			i++;
		}
		if(flag == 0)
        {
            ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
            return 0;
        }

		ft_putstr(zero);
		ft_putchar('\n');
	}
	else
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
	return 0;
}
