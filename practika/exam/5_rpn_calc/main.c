#include <stdio.h>
#include <stdlib.h>

int calc(int a, int b, char c)
{
	int rezult = 0;
	if (c == '*')
		rezult = a * b;
	else if (c == '+')
		rezult = a + b;
	else if (c == '-')
		rezult = a + b;
	else if (c == '/')
		rezult = a / b;
	else if (c == '%')
		rezult = a % b;
	return (rezult);
}

int ft_strlen_proverka(char *string)
{
	int i = 0;
	if (string[0] > 57 && string[0] < 48 && string[0] != 45)
		return (0);
	while (string[i] != 32 && ((string[i] > 47 && string[i] < 58) || (string[i] == 45)))
	{
		i++;
	}
	while (string[i] != 0 && ((string[i] > 47 && string[i] < 58) || string[i] == 37 \
		|| string[i] == 42 || string[i] == 43 || string[i] == 45 \
		|| string[i] == 32 || string[i] == 47))
	{
		i++;
		if (string[i] > 57 || string[i] < 48)
			return (0);
		while (string[i] != 32 && ((string[i] > 47 && string[i] < 58) || (string[i] == 45)))
		{
			i++;
		}
		i++;
		if (string[i] != 37 && string[i] != 42 && string[i] != 43 && \
		string[i] != 45 && string[i] != 47)
			return (0);
		i++;
	}
	return (i);
}

char	*ft_tmp(char *string, char c)
{
	int len;
	char *rez;

	if(!string)
		return (NULL);
	len = 0;
	while (string[len] && string[len++] != c)
		len++;
	rez = (char *)malloc(sizeof(char) * len);
	len = 0;
	while (string[len] && string[len] != c)
	{
		rez[len] = string[len];
		len++;
	}
	rez[len] = '\0';
	return (rez);
}

char	*ft_aftertmp(char *string, char *tmp)
{
	int i = 0;
	int len = 0;
	int flag;
	char *rez;

	if(!string || !tmp)
		return (NULL);
	while (tmp[i] && string[i] && tmp[i] == string[i])
		i++;
	i++;
	flag = i;
	while (string[i])
	{
		len++;
		i++;
	}
	i = 0;
	rez = (char *)malloc(sizeof(char) * len);
	while (string[flag] != '\0')
	{
		rez[i] = string[flag];
		flag++;
		i++;
	}
	rez[i] = '\0';
	return (rez);
}


int main(int ac, char **av)
{
	int itog = 0;
	int num = 0;
	char *tmp = NULL;
	char *znak = NULL;
	char *ostatok = NULL;

	if (ac == 2 && ft_strlen_proverka(av[1]) > 0)
	{
		tmp = ft_tmp(av[1], 32);
		itog = atoi(tmp);
		ostatok = ft_aftertmp(av[1], tmp);
		free(tmp);
		while (ostatok[0] != '\0')
		{
			tmp = ft_tmp(ostatok, 32);
			num = atoi(tmp);
			ostatok = ft_aftertmp(ostatok, tmp);
			znak = ft_tmp(ostatok, 32);
			itog = calc(itog, num, znak[0]);
			ostatok = ft_aftertmp(ostatok, znak);
			free(tmp);
			free(znak);
		}
		free(ostatok);
		printf("%d\n", itog);
	}
	else
		printf("Error\n");
	return (0);
}
