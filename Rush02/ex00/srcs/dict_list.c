#include "dict.h"
#include "dict_list.h"
#include "ft_string.h"
#include <stdlib.h>

t_dict_list 	*ft_dict_create_elem(char *key, char *value)
{
	t_dict_list	*new;

	new = (t_dict_list *)malloc(sizeof(t_dict_list));
	if (!new)
		return (0);
	new->key = key;
	new->value = value;
	new->next = 0;
	return (new);
}

void	ft_dict_add_end(t_dict_list **begin_dict, char *key, char *value)
{
	t_dict_list	*current;

	current = *begin_dict;
	if (!current)
	{
		*begin_dict = ft_dict_create_elem(key, value);
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = ft_dict_create_elem(key, value);
}

char	*search_dict(t_dict_list *begin_dict, char *number)
{
	while (begin_dict)
	{
		if (!ft_strcmp(number, begin_dict->key))
			return (begin_dict->value);
		begin_dict = begin_dict->next;
	}
	return (0);
}

char	*get_key(char *line)
{
	int		i;
	int		j;
	int		k;
	char	*key;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		++i;
	i += (line[i] == '+');
	j = i;
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	key = (char *)malloc((1 + i - j) * sizeof(char));
	if (!key)
		return (0);
	buffer_init(key, sizeof(key));
	k = 0;
	while (j < i)
	{
		key[k] = line[j];
		++j;
		++k;
	}
	return (key);
}

char	*get_value(char *line)
{
	int		i;
	char	*value;
	int		size;
	int		j;

	size = get_value_size(line);
	value = (char *)malloc((1 + size) * sizeof(char));
	if (!value)
		return (0);
	i = 0;
	while (line[i] != ':')
		++i;
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		++i;
	j = 0;
	while (j < size)
	{
		value[j] = line[i + j];
		j++;
	}
	value[j] = 0;
	return (value);
}
