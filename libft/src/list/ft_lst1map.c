/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:14:46 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 18:22:12 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1		*ft_lstmap(t_list1 *lst, t_list1 *(*f)(t_list1 *elem))
{
	t_list1	*tmp;
	t_list1	*new;
	t_list1	*head;

	if (!lst || !f || !(tmp = f(lst)))
		return (NULL);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp = f(lst)) ||\
		!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_lstdel(&head, ft_lstdelcont);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
