/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:07:10 by kplums            #+#    #+#             */
/*   Updated: 2020/01/12 19:07:12 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    return (0);
}

int ft_itpalind(char *str, int start, int finish)
{
    int i = 0;
    while (start < finish)
    {
        if(str[start] != str[finish])
            return (0);
        start++;
        finish--;
        i+=2;
    }
    if (str[start] == str[finish])
        i++;
    else
        return (0);
    return (i);
}

int main(int ac, char **av)
{
    int i = 0;
    int j;
    int size = 0;
    int start = 0;
    int finish = 0;

    if(ac == 2)
    {
        while (av[1][i] != '\0')
        {
            j = i + 1;
            while (av[1][j] != '\0')
            {
                if(ft_itpalind(av[1], i, j) > size && \
            ft_itpalind(av[1], i, j) != 0)
                {
                    size = ft_itpalind(av[1], i, j);
                    start = i;
                    finish = j;
                }
                j++;
            }
            i++;
        }

        if (size > 0)
        {
            while (start <= finish)
            {
                ft_putchar(av[1][start]);
                start++;
            }
        }
    }
    ft_putchar('\n');
    return 0;
}
