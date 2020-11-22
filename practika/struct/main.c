#include <stdio.h>
#include <stdlib.h>

//можно облегчить объявление структуры и более не писать словао struct
typedef struct hum
{
	int		age;
	char	sex;
	char 	*name;
	char 	*last_name;
} human;

//связка нескольких структур в лист
typedef struct hum1
{
	int				age;
	char			sex;
	char 			*name;
	char 			*last_name;
	struct hum1		*next;
} human1;

void 		print_human(human huma)
{
	printf("%d, %c, %s, %s\n", huma.age, huma.sex, huma.name, huma.last_name);
}

void 		print_human1(human1 huma)
{
	printf("%d, %c, %s, %s\n", huma.age, huma.sex, huma.name, huma.last_name);
}

int main()
{
	//объявление структуры, память выделяется на стеке автоматически
	human first;

	first.age = 15;
	first.sex = 'f';
	first.name = "Ksenia";
	first.last_name = "Ivanova";
	printf("Печатаем структуру first\n");
	print_human(first);

//	объявление указателя на структуру. Память уже требуется выделять через маллок
	human1 *second;

	second = (human1 *)malloc(sizeof(human1));
	second->age = 5;
	second->sex = 'm';
	second->name = "Sergey";
	second->last_name = "Petrov";
	printf("Печатаем структуру second\n");
	print_human1(*second);

//	объединение 2х структур в лист
	human1 *third;

	third = (human1 *)malloc(sizeof(human1));
	third->age = 8;
	third->sex = 'm';
	third->name = "Petr";
	third->last_name = "Sizov";

	second->next = third;
	third->next = NULL;

	printf("Печатаем лист\n");
//	Прежде чем печатать лист, нужно сохранить ссылку на первый элемент, для
//	этого работаем с временной ссылкой tmp
	human1	*tmp;

	tmp = second;
	while (tmp != NULL)
	{
		print_human1(*tmp);
		tmp = tmp->next;
	}
	return 0;


}