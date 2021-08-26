//
// Created by Mano Segransan on 8/18/21.
//
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data);

int main(void)
{
	t_list **t;
	t_list *elem;
	int n = 5;
	int j = 8;

	t = malloc(sizeof(t_list *));
	*t = ft_create_elem(&n);
	ft_list_push_back(t, &j);
	elem = *t;
	printf("%d\n", *((int *)elem->data));
	elem = elem->next;
	printf("%d\n", *((int *)elem->data));
}
