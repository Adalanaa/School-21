/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:25:20 by kplums            #+#    #+#             */
/*   Updated: 2019/12/08 17:25:24 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list*	tmp;
	int		i;

	i = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
