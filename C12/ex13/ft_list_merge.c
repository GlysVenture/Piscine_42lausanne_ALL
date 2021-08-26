#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*pos;

	if (!begin_list1)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	pos = *begin_list1;
	while (pos->next)
	{
		pos = pos->next;
	}
	pos->next = begin_list2;
}
