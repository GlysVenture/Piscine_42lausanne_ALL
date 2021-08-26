//
// Created by Mano Segransan on 8/18/21.
//
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	elem->next = *begin_list;
	*begin_list = elem;
}

t_list *ft_list_push_strs(int size, char **strs)
{
	int i;
	t_list *begin_list;

	i = -1;
	begin_list = NULL;
	while (++i < size)
		ft_list_push_front(&begin_list, strs[i]);
	return (begin_list);
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr);

int main(int argc, char **argv)
{
	t_list *begin_list;
	begin_list = ft_list_push_strs(argc, argv);
	begin_list = ft_list_at(begin_list, 1);
	printf("%s\n", (char *)begin_list->data);
}
