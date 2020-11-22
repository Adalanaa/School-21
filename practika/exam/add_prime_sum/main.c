#include <unistd.h>


int	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_atoi_base(char* str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (str[i] == '-')
		return (0);
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}
int ft_itsprime (int n)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	if (n == 1 || n == 0)
		return (0);
	if (n < 4)
		return (1);
	else
	{
		while (i <= n)
		{
			if (n % i == 0)
				flag++;
			i++;
		}
		if (flag == 2)
			return (1);
		else
			return (0);
	}
}

int ft_sum_prime(int n)
{
	int	sum;
	int i;
	i = 0;
	while (i <= n)
	{
		if (ft_itsprime(i) == 1)
			sum+=i;
		i++;
	}
	return (sum);
}

int ft_write_sum(int n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_write_sum(n / 10);
		ft_putchar((n % 10) + '0');

	}
	return (0);
}

int main(int ac, char** av)
{
	if (ac == 2 && ft_atoi_base(av[1]) > 0)
	{
		ft_write_sum( ft_sum_prime(ft_atoi_base(av[1])));
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
