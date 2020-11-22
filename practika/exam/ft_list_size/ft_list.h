/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:26:27 by kplums            #+#    #+#             */
/*   Updated: 2019/12/08 17:26:33 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct    s_list
{
	struct s_list *next;
	void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list);

#endif FT_LIST_H
