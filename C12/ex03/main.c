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

t_list *ft_list_last(t_list *begin_list);

int main(void)
{
	t_list **t;
	t_list *elem;
	int n = 5;
	int j = 8;

	t = malloc(sizeof(t_list *));
	*t = ft_create_elem(&n);
	ft_list_push_front(t, &j);
	elem = ft_list_last(*t);
	printf("%d\n", *((int *)elem->data));
}
