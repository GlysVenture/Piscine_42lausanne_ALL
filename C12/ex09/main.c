//
// Created by Mano Segransan on 8/18/21.
//
#include "ft_list.h"
#include <unistd.h>
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


void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(void *nb)
{
	printf("%d\n", *((int *)nb));
}

void	ft_list_foreach(t_list *begin_list, void(*f)(void*));

int main(void)
{
	t_list **t;
	int n = 5;
	int j = 8;

	t = malloc(sizeof(t_list *));
	*t = ft_create_elem(&n);
	ft_list_push_front(t, &j);
	ft_list_foreach(*t, &ft_putnbr);
}
