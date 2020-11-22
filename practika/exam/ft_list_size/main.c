#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	t_list*	list1 = (t_list*)malloc(sizeof(t_list));
	t_list*	list2 = (t_list*)malloc(sizeof(t_list));
	t_list*	list3 = (t_list*)malloc(sizeof(t_list));
	list1->next = list2;
	list2->next = list3;
	list3->next = NULL;
	printf("%d", ft_list_size(list1));
	return 0;
}
