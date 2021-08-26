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


void	ft_putstr(void *str)
{
	printf("%s\n", (char *)str);
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		++i;
	}
	if (s1[i] == s2[i])
		return (0);
	return (-s2[i]);
}

int comp(void *a, void *b)
{
	return (ft_strcmp((char *)a, (char *)b));
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int(*cmp)());

int main(int argc, char **argv)
{
	t_list *t;
	char *s = "fscX2rw";

	t = ft_list_push_strs(argc - 1, &argv[1]);
	ft_list_foreach(t, &ft_putstr);
	ft_sorted_list_insert(&t, s, comp);
	ft_putchar('\n');
	ft_list_foreach(t, &ft_putstr);
}
