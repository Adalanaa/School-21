/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:28:50 by kplums            #+#    #+#             */
/*   Updated: 2019/11/28 17:43:40 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	char	*new;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	arr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (arr == NULL)
		return (NULL);
	new = ft_strcpy(arr, s1);
	newstr = ft_strcat(new, s2);
	return (newstr);
}
