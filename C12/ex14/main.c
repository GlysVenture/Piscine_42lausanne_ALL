//
// Created by Mano Segransan on 8/18/21.
//
#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

t_list 	*ft_create_elem(void *data)
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

void	ft_list_foreach(t_list *begin_list, void(*f)(void*))
{
	t_list	*elem;

	elem = begin_list;
	while (elem != NULL)
	{
		f(elem->data);
		elem = elem->next;
	}
}

int comp(void *nb, void *cp)
{
	return (*((int *)nb) - *((int *)cp));
}

void	ft_list_sort(t_list **begin_list, int(*cmp)());

int main(void)
{
	t_list **t;
	int l = 23;
	int *k =(int*)malloc(sizeof(int));
	int j = 8;
	int n = 9;

	*k = 9;
	t = malloc(sizeof(t_list *));
	*t = ft_create_elem(&n);
	ft_list_push_front(t, &j);
	ft_list_push_front(t, &l);
	ft_list_push_front(t, k);
	ft_list_foreach(*t, &ft_putnbr);
	ft_list_sort(t, comp);
	ft_putchar('\n');
	ft_list_foreach(*t, &ft_putnbr);
}
