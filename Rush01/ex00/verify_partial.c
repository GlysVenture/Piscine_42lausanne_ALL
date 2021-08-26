#include "verify_partial.h"

int	verify_partial_matrix(int **matrix, int *rules, int n, int depth)
{
	int	x;
	int	y;

	x = depth / n;
	y = depth % n;
	if (check_array_numbers_partial(matrix[x], n, y)
		&& check_rules_partial(matrix[x], rules[x], n)
		&& check_rules_partial_rev(matrix[x], rules[n + x], n)
		&& check_array_n_partial_row(matrix, y, n, x)
		&& check_r_partial_row(matrix, y, rules[2 * n + y], n)
		&& check_r_partial_row_rev(matrix, y, rules[3 * n + y], n))
		return (1);
	return (0);
}

int	check_array_numbers_partial(int *array, int n, int x)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (i != x && array[i] == array[x] && array[i] != 0)
			return (0);
	}
	return (1);
}

int	check_rules_partial(int *array, int rule, int n)
{
	int	i;
	int	counter;
	int	counter2;
	int	prev;

	i = -1;
	counter = 0;
	counter2 = 0;
	prev = 0;
	while (++i < n)
	{
		if (array[i] == 0)
			return (counter <= rule && !(counter2 > n - rule));
		if (array[i] > prev)
		{
			prev = array[i];
			counter++;
		}
		else
			counter2++;
	}
	return (counter == rule);
}

int	check_rules_partial_rev(int *array, int rule, int n)
{
	int	i;
	int	counter;
	int	prev;

	i = n;
	counter = 0;
	prev = 0;
	while (--i >= 0)
	{
		if (array[i] == 0)
			return (counter <= rule);
		if (array[i] > prev)
		{
			prev = array[i];
			counter++;
		}
	}
	return (counter == rule);
}
