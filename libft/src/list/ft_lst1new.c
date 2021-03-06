/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:59:05 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 19:33:34 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1				*ft_lstnew(void const *content, size_t content_size)
{
	t_list1	*list;

	if (!(list = (t_list1 *)malloc(sizeof(t_list1))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
			return (NULL);
		if (!content_size)
			list->content_size = 0;
		else
		{
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
	}
	list->next = NULL;
	return (list);
}
