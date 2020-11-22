/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:49:38 by unite             #+#    #+#             */
/*   Updated: 2019/07/14 17:47:38 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDK_H
# define SDK_H
# include <stdlib.h>

char	*sdk_unroll(int argc, char **argv);
char	*sdk_copy(char *sdk);
int		sdk_clashed(int pos1, int pos2);
int		sdk_putnum(char *sdk, int pos1, char num);
void	sdk_print(char *sdk);
char	*sdk_solve(char *sdk);
int		sdk_solnchecker(char *sdk);

#endif
