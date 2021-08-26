#include "check_value.h"
#include "error_msg.h"
#include "trim.h"

int	handle_sign(char *val, int i)
{
	if (val[i] == '-')
	{
		if (!is_zero(&val[i]))
			return (0);
		val[i] = ' ';
		++i;
	}
	if (val[i] == '+')
	{
		val[i] = ' ';
		++i;
	}
	return (i);
}

int	check_value_to_convert(char *val)
{
	int	i;

	trim_trailing_whitespaces(val);
	i = 0;
	while (val[i] == ' ' || val[i] == '\t')
		++i;
	i = handle_sign(val, i);
	while (val[i])
	{
		if (!(val[i] >= '0' && val[i] <= '9'))
			return (0);
		++i;
	}
	trim_leading_zeroes(val);
	trim_leading_whitespaces(val);
	return (1);
}

int	check_value_length(char *val)
{
	int		i;

	i = 0;
	while (val[i] >= '0' && val[i] <= '9')
		++i;
	if (!i || (i > 39))
		return (0);
	return (1);
}

int	check_argc(int argc, char **argv)
{
	if (argc < 2 || 3 < argc)
		return (INVALID_ARG_COUNT);
	if (!check_value_to_convert(argv[argc - 1]))
		return (INVALID_INT_INPUT);
	if (!check_value_length(argv[argc - 1]))
		return (CANNOT_CONVERT_INT);
	return (0);
}

char	*number_selector(int argc, char *argv[])
{
	return (argv[argc - 1]);
}
