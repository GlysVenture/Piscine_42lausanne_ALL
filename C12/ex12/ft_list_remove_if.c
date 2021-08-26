#include "ft_list.h"
#include <stdlib.h>

void	ft_clear_beg(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void*));

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
					   void (*free_fct)(void*))
{
	t_list	*last;
	t_list	*current;

	if (!begin_list)
		return ;
	ft_clear_beg(begin_list, data_ref, cmp, free_fct);
	if (!*begin_list)
		return ;
	current = (*begin_list)->next;
	last = *begin_list;
	while (current)
	{
		if (!(*cmp)(current->data, data_ref))
		{
			last->next = current->next;
			(*free_fct)(current->data);
			free(current);
			current = last->next;
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}

void	ft_clear_beg(t_list **begin_list, void *data_ref, int (*cmp)(),
				  void (*free_fct)(void*))
{
	t_list	*current;

	while (*begin_list && !(*cmp)((*begin_list)->data, data_ref))
	{
		current = (*begin_list)->next;
		(*free_fct)((*begin_list)->data);
		free(*begin_list);
		*begin_list = current;
	}
}
