#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list);
void	ft_swap_data(t_list *a, t_list *b);

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*temp;
	t_list	*temp_next;
	t_list	*temp_last;

	if (!begin_list)
		return ;
	temp_last = ft_list_last(begin_list);
	ft_swap_data(begin_list, temp_last);
	temp_next = begin_list->next;
	temp = temp_next;
	while (temp_next && temp_next->next)
	{
		temp = temp_next;
		temp_next = temp_next->next;
		temp->next = temp_last;
		temp_last = temp;
	}
	begin_list->next = temp;
}

void	ft_swap_data(t_list *a, t_list *b)
{
	void	*temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
