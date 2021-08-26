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

int comp(void *nb, void *cp)
{
	return (((char *)nb)[0] != ((char *)cp)[0]);
}

void	ft_putnbr(void *nb)
{
	printf("%s\n", (char *)nb);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin_list;

	i = -1;
	begin_list = NULL;
	while (++i < size)
		ft_list_push_front(&begin_list, strs[i]);
	return (begin_list);
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

void	do_nothing(void *i)
{
	(void)i;
	return;
}
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

int main(int argc, char **argv)
{
	t_list *t;
	t_list *u;

	t = ft_list_push_strs(2, &argv[1]);
	u = ft_list_push_strs(argc - 3, &argv[3]);
	ft_list_foreach(t, &ft_putnbr);
	ft_putchar('\n');
	ft_list_merge(&t, u);
	ft_list_foreach(t, &ft_putnbr);
}
