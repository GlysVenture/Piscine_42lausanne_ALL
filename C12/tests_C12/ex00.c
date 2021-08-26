#include "../ex00/ft_create_elem.c"
#include "../ex00/ft_list.h"
#include <stdio.h>

int main(void)
{
	char	*data1;
	int		*data2;
	t_list	*elem1;
	t_list	*elem2;

	data1 = malloc(sizeof(char));
	data2 = malloc(sizeof(int));
	*data1 = 't';
	*data2 = 15;
	elem1 = ft_create_elem(data1);
	printf("expected : t\nresult : %c\nnext : %p\n", *(char*)elem1->data, elem1->next);
	elem2 = ft_create_elem(data2);
	printf("expected : 15\nresult : %d\nnext : %p\n", *(int*)elem2->data, elem2->next);
	return (0);
}

