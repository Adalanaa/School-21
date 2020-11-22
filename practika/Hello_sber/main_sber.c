/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <kplums@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:08:44 by kplums            #+#    #+#             */
/*   Updated: 2019/10/18 20:43:58 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Created by Vlasova Natalia (kplums) on 18/10/2019.
//

#include <stdio.h>
#include <locale.h>
#include <wchar.h>
# define LINE 200

void	rusalflower(wchar_t *av);
size_t	ft_strlen(const char *s);
char	*ft_strstr(const char *haystack, const char *needle);

int	main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	wchar_t *cennosti;
	int i = 0;

	cennosti = \
    L"\bНаши ценности – основа отношения к жизни и работе, внутренний компас, \n\
помогающий принимать решения в сложных ситуациях, принципы, верность которым \n\
мы храним всегда и везде.";
	wchar_t **varcen = {
			L"ценности",
			L"ценост",
			L"ценност",
	};
	wchar_t str[LINE];
	wprintf(L"%s\n", "Привет, что Вас интересует?");
	fgets((char *)str, LINE, stdin);
	rusalflower((wchar_t *) str);
//	wprintf(L"Мой ответ: %ls\n", str);
	while (*varcen)
	{
		if (ft_strstr((const char *)str, (const char *)varcen) != NULL && \
		ft_strstr((const char *)str, (const char *)varcen) != (char *)str)
		{
			wprintf(L"Мой ответ:\n %ls\n", cennosti);
			break;
		}
		varcen++;
	}
	return (0);
}

void	rusalflower(wchar_t *av)
{
	while (*av)
	{
		if (*av >= L'А' && *av <= L'Я')
			*av = *av + 32;
		av++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j])
		j++;
	return (j);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j]\
		&& needle[j])
			j++;
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}