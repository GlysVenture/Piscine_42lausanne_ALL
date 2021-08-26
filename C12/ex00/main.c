//
// Created by Mano Segransan on 8/18/21.
//
#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data);

int main(void)
{
	t_list *t;
	int n = 5;

	t = ft_create_elem(&n);

	printf("%d", *((int *)t->data));
}