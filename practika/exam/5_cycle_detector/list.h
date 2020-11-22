/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:24:29 by kplums            #+#    #+#             */
/*   Updated: 2020/01/12 19:24:31 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAD_H
#define FT_HEAD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct      s_list
{
    int             data;
    struct s_list   *next;
}                   t_list;

int        cycle_detector(const t_list *list);

#endif FT_HEAD_H
