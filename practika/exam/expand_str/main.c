#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int main(int ac, char** av)
{
	int	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] != 32 && av[1][i] != '\t' && av[1][i] != '\n')
			{
				ft_putchar(av[1][i]);
				if (av[1][i + 1] == 32 || av[1][i + 1] == '\t' || av[1][i + 1] == '\n')
				{
					i++;
					while (av[1][i] == 32 || av[1][i] == '\t' || av[1][i] == '\n')
						i++;
					if (av[1][i] == '\0')
					{
						ft_putchar('\n');
						return 0;
					}
					ft_putchar(' ');
					ft_putchar(' ');
					ft_putchar(' ');
					ft_putchar(av[1][i]);
				}
			}
			i++;
		}
	}
	ft_putchar('\n');
	return 0;
}
