#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*needle;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	needle = *begin_list;
	while (needle->next)
	{
		needle = needle->next;
	}
	needle->next = ft_create_elem(data);
}
