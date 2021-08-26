#include "trim.h"
#include "ft_string.h"

void	trim_leading_whitespaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	if (str[i] == '+')
		++i;
	if (i)
	{
		j = 0;
		while (str[i])
		{
			str[j] = str[i];
			++i;
			++j;
		}
		while (j < i)
		{
			str[j] = 0;
			++j;
		}
	}
}

void	trim_trailing_whitespaces(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (--len >= 0)
	{
		if (str[len] == ' ' || str[len] == '\t')
			str[len] = 0;
		else
			break ;
	}
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		if (str[i] != '0')
			return (0);
	return (1);
}

void	trim_leading_zeroes(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	while (str[i] == '0' && str[i + 1] == '0')
	{
		str[i] = ' ';
		++i;
	}
	if (str[i] == '0' && str[i + 1] && str[i + 1] != '0')
		str[i] = ' ';
}
