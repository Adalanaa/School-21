#include <stdio.h>

int main(int ac, char** av)
{
	char *a;
	a = av[1] - '0';
	printf("%s", a);
	return (0);
}