#include "check_dict_syntax.h"
#include <stdlib.h>

char	*read_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc((1 + i) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		++i;
	}
	line[i] = 0;
	return (line);
}

int	check_dict_syntax(char *str)
{
	int	i;
	int	value_found;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	if ((str[i] < '0' || str[i] > '9') && str[i++] != '+')
		return (0);
	if (str[i - 1] == '+' && (str[i] < '0' || str[i] > '9'))
		return (0);
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] && str[i] != ':'))
		++i;
	if (!str[i++])
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	value_found = 0;
	while (str[i])
	{
		if ((str[i] < ' ' && str[i] != '\t') || str[i] > '~')
			return (0);
		else
			value_found = ++i;
	}
	return (value_found);
}
