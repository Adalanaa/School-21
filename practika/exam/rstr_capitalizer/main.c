#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int main(int ac, char** av)
{
	int j = 1;
	if (ac > 1)
	{
		while (av[j])
		{
			int	i = 0;
			while (av[j][i])
			{
				if (av[j][i] < 91 && av[j][i] > 64 && av[j][i + 1] != 32 &&
				av[j][i + 1] != '\t' && av[j][i + 1] != '\n' &&
				av[j][i + 1] != '\0')
					av[j][i] = av[j][i] + 32;
				else if (av[j][i] < 123 && av[j][i] > 96 &&
				(av[j][i + 1] == 32 ||av[j][i + 1] == '\t' ||
				av[j][i + 1] == '\n' || av[j][i + 1] == '\0'))
					av[j][i] = av[j][i] - 32;
				ft_putchar(av[j][i]);
				i++;
			}
			j++;
		}
	}
	ft_putchar('\n');
	return 0;
}
