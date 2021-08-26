int	check_array_n_partial_row(int **matrix, int nrow, int n, int x)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (i != x && matrix[i][nrow] == matrix[x][nrow]
				&& matrix[i][nrow] != 0)
			return (0);
	}
	return (1);
}

int	check_r_partial_row(int **matrix, int nrow, int rule, int n)
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
		if (matrix[i][nrow] == 0)
			return (counter <= rule && !(counter2 > n - rule));
		if (matrix[i][nrow] > prev)
		{
			prev = matrix[i][nrow];
			counter++;
		}
		else
			counter2++;
	}
	return (counter == rule);
}

int	check_r_partial_row_rev(int **matrix, int nrow, int rule, int n)
{
	int	i;
	int	counter;
	int	prev;

	i = n;
	counter = 0;
	prev = 0;
	while (--i >= 0)
	{
		if (matrix[i][nrow] == 0)
			return (counter <= rule);
		if (matrix[i][nrow] > prev)
		{
			prev = matrix[i][nrow];
			counter++;
		}
	}
	return (counter == rule);
}
