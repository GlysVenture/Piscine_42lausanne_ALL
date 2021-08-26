#include "ft_list_out.h"
#include "dict_list.h"
#include "ft_number_letter.h"
#include "ft_string.h"
#include <stdlib.h>

void	ft_add_str(t_out_list **l, t_dict_list *d, char *numb, int *v)
{
	int		n;
	int		bool;

	n = ft_strlen(numb);
	bool = (n - 1 > *v && '0' != numb[n - *v - 2]) || (numb[n - *v] != '0');
	if (*v == 1)
	{
		if (n > *v && '1' == numb[n - *v - 1])
			ft_out_add_beg(l, ft_search_numb(d, numb[n - (*v)++], -3));
		else
			ft_out_add_beg(l, ft_search_numb(d, numb[n - *v], -1));
	}
	else if ((*v - 1) % 3 == 0 || (*v - 1) % 3 == 2)
	{
		if ((*v - 1) % 3 == 2)
			ft_out_add_beg(l, ft_search_numb(d, numb[n - *v], -4));
		else if ((n > *v && '0' != numb[n - *v - 1]) || bool)
			ft_out_add_beg(l, ft_search_numb(d, numb[n - *v], *v));
		if (n > *v && '1' == numb[n - *v - 1] && (*v - 1) % 3 == 0)
			ft_out_add_beg(l, ft_search_numb(d, numb[n - (*v)++], -3));
		else
			ft_out_add_beg(l, ft_search_numb(d, numb[n - *v], -1));
	}
	else if ((*v - 1) % 3 == 1)
		ft_out_add_beg(l, ft_search_numb(d, numb[n - *v], -2));
}

char	*ft_store_string(char *str)
{
	char	*out;
	int		i;

	i = 0;
	out = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!out)
		return (0);
	while (str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

char	*ft_neg_tofind(char numb, int info)
{
	char	*to_find;

	to_find = ft_store_string("100");
	if (info == -1 || info == -2)
	{
		to_find[0] = numb;
		to_find[1] = 0;
	}
	if (info == -2)
	{
		to_find[1] = '0';
		to_find[2] = 0;
	}
	if (info == -3)
	{
		to_find[0] = '1';
		to_find[1] = numb;
		to_find[2] = 0;
	}
	if (!info)
	{
		to_find[0] = '0';
		to_find[1] = 0;
	}
	return (to_find);
}
