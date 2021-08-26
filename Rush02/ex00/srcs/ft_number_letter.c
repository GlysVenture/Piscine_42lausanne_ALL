#include "ft_number_letter.h"
#include "ft_list_out.h"
#include "ft_string.h"
#include <stdlib.h>
#include "dict_list.h"

t_out_list	*ft_get_list(t_dict_list *begin_dict, char *numb)
{
	t_out_list	*list;

	list = NULL;
	if (numb[0] == '0' && ft_strlen(numb) == 1)
		ft_out_add_beg(&list, ft_search_numb(begin_dict, numb[0], 0));
	ft_add_strings(&list, begin_dict, numb);
	return (list);
}

void	ft_add_strings(t_out_list **l, t_dict_list *d, char *numb)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(numb);
	while ((i) < len)
	{
		i++;
		ft_add_str(l, d, numb, &i);
	}
}

char	*ft_search_numb(t_dict_list *begin_dict, char numb, int info)
{
	char	*to_find;
	char	*out;

	if (info < 0 && numb == '0' && info != -3)
		return (0);
	to_find = ft_get_findable(numb, info);
	out = search_dict(begin_dict, to_find);
	if (to_find)
		free(to_find);
	return (out);
}

char	*ft_get_findable(char numb, int info)
{
	char	*to_find;
	int		i;

	if (info <= 0)
	{
		to_find = ft_neg_tofind(numb, info);
		return (to_find);
	}
	i = 0;
	to_find = malloc(sizeof(char) * info + 1);
	if (!to_find)
		return (0);
	to_find[0] = '1';
	while (++i < info)
		to_find[i] = '0';
	to_find[i] = 0;
	return (to_find);
}
