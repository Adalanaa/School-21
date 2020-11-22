#include <unistd.h>
#include <stdio.h>

int		ft_atoi(char* av)
{
	int	n = 0;
	int i = 0;
	while (av[i] != '\0')
	{
		n = n * 10 + (av[i] - '0');
		i++;
	}
	return (n);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int ft_hex(int n)
{
	if (n >= 16)
	{
		ft_hex(n / 16);
		ft_hex(n % 16);
	}
	else
	{
		if (n % 16 <= 9)
			ft_putchar(n + '0');
		if (n % 16 == 10)
			ft_putchar('a');
		if (n % 16 == 11)
			ft_putchar('b');
		if (n % 16 == 12)
			ft_putchar('c');
		if (n % 16 == 13)
			ft_putchar('d');
		if (n % 16 == 14)
			ft_putchar('e');
		if (n % 16 == 15)
			ft_putchar('f');
	}
	return (0);
}

int main(int ac, char** av)
{
	if (ac == 2 && ft_atoi(av[1]) >= 0)
	{
		int	n = ft_atoi(av[1]);
		ft_hex(n);
	}
	ft_putchar('\n');
	return 0;
}
