#include "ft_list_out.h"
#include <unistd.h>
#include <stdlib.h>
#include "ft_string.h"

t_out_list 	*ft_out_create_elem(char *data)
{
	t_out_list	*new;

	new = (t_out_list *)malloc(sizeof(t_out_list));
	if (!new)
		return (0);
	new->str = data;
	new->next = 0;
	return (new);
}

void	ft_out_add_beg(t_out_list **begin_list, char *data)
{
	t_out_list	*temp;

	temp = *begin_list;
	*begin_list = ft_out_create_elem(data);
	(*begin_list)->next = temp;
}

void	ft_out_list_print(t_out_list *begin_list)
{
	int			i;
	t_out_list	*temp;

	while (begin_list)
	{
		i = 0;
		if (begin_list->str)
		{
			while ((begin_list->str)[i])
			{
				write(1, (begin_list->str) + i, 1);
				i++;
			}
			if (begin_list->next)
				ft_putchar(' ');
		}
		temp = begin_list->next;
		free(begin_list);
		begin_list = temp;
	}
	ft_putchar('\n');
}
