/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:39:43 by kplums            #+#    #+#             */
/*   Updated: 2020/09/27 16:39:45 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_parser_1arg(char **argv, char **num_arr, char *arr, char *line)
{
	int fd;

	if ((fd = open(*(argv), O_RDWR)) > 0)
	{
		while (get_next_line(fd, &line) == 1)
		{
			if (checkline_int_space(line) == 0)
				ft_exit_error(105);
			if (!arr)
				arr = ft_strdup(line);
			else
				arr = ft_strjoin(arr, line);
			ft_memdel((void **)&line);
		}
		ft_memdel((void **)&line);
		num_arr = ft_strsplit(arr, ' ');
		ft_memdel((void **)&arr);
		close(fd);
	}
	else if (checkline_int_space(*(argv)) == 0)
		ft_exit_error(106);
	else
		num_arr = ft_strsplit(*(argv), ' ');
	return (num_arr);
}

char	**ft_parser_2argv(int ac, char **argv, int i, char **num_arr)
{
	char	*arr;
	char	*tmp;

	arr = NULL;
	tmp = NULL;
	while (++i < ac)
	{
		if (checkline_int_space(argv[i]) == 0)
			ft_exit_error(107);
		if (!arr)
			tmp = ft_strdup(argv[i]);
		else
			tmp = ft_strjoin(arr, argv[i]);
		ft_memdel((void **)&arr);
		arr = ft_strjoin(tmp, " ");
		ft_memdel((void **)&tmp);
	}
	num_arr = ft_strsplit(arr, ' ');
	ft_memdel((void **)&arr);
	return (num_arr);
}

char	**ft_parser_argv(int ac, char **argv, t_save *save, char **num_arr)
{
	int		i;

	i = 0;
	if (ft_strequ(argv[1], "-v"))
	{
		save->flag_v = 1;
		save->flag_count++;
		i++;
	}
	if (!(argv + 1 + save->flag_count))
		exit(102);
	if (ac - save->flag_count - 1 == 1)
		num_arr = ft_parser_1arg(argv + 1 + save->flag_count, NULL, NULL, NULL);
	else
		num_arr = ft_parser_2argv(ac, argv, i, NULL);
	if (!num_arr)
		exit(102);
	return (num_arr);
}

int		*ft_digital_arr(char **num_arr, t_save *save)
{
	int	i;
	int j;
	int	*digital_arr;

	i = -1;
	digital_arr = NULL;
	while (num_arr[save->len])
		save->len++;
	digital_arr = (int *)ft_malloc(save->len, sizeof(int));
	while (++i < save->len)
	{
		j = i;
		digital_arr[i] = ft_atoi(num_arr[i]);
		if ((ft_strchr(num_arr[i], '-') && digital_arr[i] > 0) || \
		(!(ft_strchr(num_arr[i], '-')) && digital_arr[i] < 0) || \
		(ft_strlen(num_arr[i]) > 11))
			ft_exit_error(111);
		while (--j >= 0)
			if (digital_arr[i] == digital_arr[j])
				ft_exit_error(108);
	}
	return (digital_arr);
}

void	push_swap_parser(int ac, t_save *save, char **argv, char **num_arr)
{
	int i;

	i = -1;
	save->flag_count = 0;
	save->flag_v = 0;
	num_arr = ft_parser_argv(ac, argv, save, NULL);
	if (!num_arr)
		exit(102);
	save->dig_arr = ft_digital_arr(num_arr, save);
	while (num_arr[++i])
		ft_memdel((void **)&(num_arr[i]));
	ft_memdel((void **)&num_arr);
	i = 0;
	while (i + 1 < save->len && save->dig_arr[i] < save->dig_arr[i + 1])
		if (save->dig_arr[i] < save->dig_arr[i + 1])
			i++;
	if (i + 1 == save->len && save->flag_checker == 0)
		exit(109);
}
