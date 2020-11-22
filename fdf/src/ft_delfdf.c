/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delfdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:16 by kplums            #+#    #+#             */
/*   Updated: 2020/02/16 16:29:18 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_delmatrix(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->matrix[i])
	{
		while (fdf->matrix[i])
		{
			free(fdf->matrix[i]);
			fdf->matrix[i] = NULL;
			i++;
		}
	}
	free(fdf->matrix);
	fdf->matrix = NULL;
}

void	ft_delfdf(t_fdf *fdf)
{
	if (fdf->matrix != NULL)
        ft_delmatrix(fdf);
	ft_memdel((void **)&fdf);
}
