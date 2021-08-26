#include "ft_rules.h"

static int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_count(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i % 2))
			return (-1);
		if (!is_numeric(str[i]) && !(i % 2))
			return (-1);
		i++;
	}
	i++;
	if ((i % 2) || ((i / 2) % 4) || (i / 8) > 9)
		return (-1);
	return (i / 8);
}

int	*ft_store_rules(char *str, int size)
{
	int		*rules;
	int		i;

	i = 0;
	rules = malloc(sizeof(int) * size * 4);
	while (str[i] && i < size * 8)
	{
		rules[i / 2] = str[i] - '0';
		i += 2;
	}
	return (rules);
}
