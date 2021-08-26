#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*pos;
	t_list	*new;

	if (!*begin_list || (*cmp)(data, (*begin_list)->data) <= 0)
	{
		pos = *begin_list;
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = pos;
		return ;
	}
	pos = *begin_list;
	while (pos->next)
	{
		if ((*cmp)(data, pos->next->data) <= 0)
		{
			new = ft_create_elem(data);
			new->next = pos->next;
			pos->next = new;
			return ;
		}
		pos = pos->next;
	}
	pos->next = ft_create_elem(data);
}
