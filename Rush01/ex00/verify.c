#include "verify.h"

int	verify_matrix(int **matrix, int *rules, int n)
{
	int	i;
	int	*row;
	int	res;

	if (matrix == NULL)
		return (0);
	i = -1;
	res = 1;
	while (++i < n)
	{
		row = extract_row(matrix, i, n);
		res *= check_array_numbers(row, n);
		res *= check_array_numbers(matrix[i], n);
		res *= check_rules(row, rules[2 * n + i], rules[3 * n + i], n);
		res *= check_rules(matrix[i], rules[i], rules[n + i], n);
		free(row);
		if (!res)
			return (0);
	}
	return (1);
}

int	check_array_numbers(int *array, int n)
{
	int	*used;
	int	i;

	used = malloc(n * sizeof(n));
	i = -1;
	while (++i < n)
		used[i] = 0;
	i = -1;
	while (++i < n)
		used[array[i] - 1]++;
	i = -1;
	while (++i < n)
	{
		if (used[i] != 1)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

int	check_rules(int *array, int r1, int r2, int n)
{
	int	i;
	int	counter1;
	int	counter2;
	int	prev1;
	int	prev2;

	i = -1;
	counter1 = 0;
	counter2 = 0;
	prev1 = 0;
	prev2 = 0;
	while (++i < n)
	{
		if (array[i] > prev1)
		{
			prev1 = array[i];
			counter1++;
		}
		if (array[n - 1 - i] > prev2)
		{
			prev2 = array[n - 1 - i];
			counter2++;
		}
	}
	return (counter1 == r1 && counter2 == r2);
}	

int	*extract_row(int **matrix, int nrow, int n)
{
	int	i;
	int	*row;

	row = malloc(n * sizeof(n));
	i = -1;
	while (++i < n)
		row[i] = matrix[i][nrow];
	return (row);
}
