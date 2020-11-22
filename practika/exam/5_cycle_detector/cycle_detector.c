/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:23:20 by kplums            #+#    #+#             */
/*   Updated: 2020/01/12 19:23:22 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static t_list *ft_copir(t_list *tmp, int i)
{
    t_list *vrem;

    vrem = (t_list *)malloc(sizeof(t_list) * i);
    while (i >= 0)
    {
        vrem->data = tmp->data;
        vrem->next - tmp->next;
        vrem = vrem->next;
        tmp = tmp->next;
        i--;
    }
    vrem->next = NULL;
    return (vrem);
}

int        cycle_detector(const t_list *list)
{
    int i = 1;
    t_list *tmp;
    t_list *vrem;

    tmp = list;
    while (tmp != NULL)
    {
        vrem = ft_copir(tmp, i);
        while (vrem)
        {
            i
        }
    }
    return (0);
}
