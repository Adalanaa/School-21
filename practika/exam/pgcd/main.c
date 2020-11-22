#include <stdio.h>
#include <stdlib.h>

int main(int ac, char** av)
{
	if (ac == 3 && atoi(av[1]) > 0 && atoi(av[2]))
	{
		int a = atoi(av[1]);
		int b = atoi(av[2]);
		int i = 1;
		int hi = i;
		while (i <= a && i <=b)
		{
			if (a % i == 0 && b % i == 0)
				hi = i;
			i++;
		}
		printf("%d", hi);
	}
	printf("\n");
	return (0);
}
