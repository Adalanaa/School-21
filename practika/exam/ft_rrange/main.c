#include <stdio.h>

int     *ft_rrange(int start, int end);

int main()
{
	int start = 100;
	int end = 56;
	int i;
	i = 0;
	while (*(ft_rrange(start, end) + i) != start)
		printf("%d\n",  *(ft_rrange(start, end) + i++));
	printf("%d",  *(ft_rrange(start, end) + i));
	return 0;
}
