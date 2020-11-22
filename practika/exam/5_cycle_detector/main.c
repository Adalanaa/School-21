/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:23:10 by kplums            #+#    #+#             */
/*   Updated: 2020/01/12 19:23:13 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int main()
{
    t_list  *no1;
    t_list  *no2;
    t_list  *no3;
    t_list  *no4;

    no1->data = 1;
    no2->data = 2;
    no3->data = 3;
    no4->data = 4;

    no1->next = no2;
    no2->next = no3;
    no3->next = no4;
    no4->next = no1;

    printf("%d", cycle_detector(no1);)
    return 0;
}
