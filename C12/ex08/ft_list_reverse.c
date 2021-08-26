#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp;
	t_list	*temp_next;
	t_list	*temp_last;

	temp_last = 0;
	temp = 0;
	temp_next = *begin_list;
	while (temp_next)
	{
		temp = temp_next;
		temp_next = temp_next->next;
		temp->next = temp_last;
		temp_last = temp;
	}
	*begin_list = temp;
}
