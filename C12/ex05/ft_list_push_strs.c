#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*last;
	t_list	*new;

	i = 0;
	last = 0;
	while (i < size)
	{
		new = ft_create_elem(strs[i]);
		new->next = last;
		last = new;
		i++;
	}
	return (last);
}
