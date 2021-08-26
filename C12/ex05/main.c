//
// Created by Mano Segransan on 8/18/21.
//
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

t_list *ft_list_push_strs(int size, char **strs);

int main(int argc, char **argv)
{
	t_list *begin_list;
	begin_list = ft_list_push_strs(argc, argv);

	int i = -1;
	while (++i < argc)
	{
		printf("%s\n", (char *)begin_list->data);
		begin_list = begin_list->next;
	}
}
