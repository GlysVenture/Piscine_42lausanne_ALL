#include "ft_list.h"

int		ft_is_sort_list(t_list *begin_list, int (*cmp)());
void	ft_swap_data(t_list *a, t_list *b);

void	ft_list_sort(t_list **beginlist, int (*cmp)())
{
	t_list	*pos;

	while (!ft_is_sort_list(*beginlist, cmp))
	{
		pos = *beginlist;
		while (pos && pos->next)
		{
			if ((*cmp)(pos->data, pos->next->data) > 0)
				ft_swap_data(pos, pos->next);
			pos = pos->next;
		}
	}
}

int	ft_is_sort_list(t_list *begin_list, int (*cmp)())
{
	if (!begin_list || !begin_list->next)
		return (1);
	while (begin_list && begin_list->next)
	{
		if ((*cmp)(begin_list->data, begin_list->next->data) > 0)
			return (0);
		begin_list = begin_list->next;
	}
	return (1);
}

void	ft_swap_data(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}
