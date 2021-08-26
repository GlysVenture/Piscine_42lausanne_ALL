#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list,
			   t_list *insert, int (*cmp)());

void	ft_sorted_list_merge(t_list **begin_list1,
						  t_list *begin_list2, int (*cmp)())
{
	t_list	*temp;

	while (begin_list2)
	{
		temp = begin_list2->next;
		begin_list2->next = 0;
		ft_sorted_list_insert(begin_list1, begin_list2, cmp);
		begin_list2 = temp;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, t_list *insert, int (*cmp)())
{
	t_list	*pos;

	if (!*begin_list || (*cmp)(insert->data, (*begin_list)->data) <= 0)
	{
		pos = *begin_list;
		*begin_list = insert;
		(*begin_list)->next = pos;
		return ;
	}
	pos = *begin_list;
	while (pos->next)
	{
		if ((*cmp)(insert->data, pos->next->data) <= 0)
		{
			insert->next = pos->next;
			pos->next = insert;
			return ;
		}
		pos = pos->next;
	}
	pos->next = insert;
}
