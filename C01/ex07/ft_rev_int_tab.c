void	ft_rev_int_tab(int *tab, int size)
{
	int		t;
	int		i;

	i = 0;
	while (i < (size / 2))
	{
		t = *(tab + (size - i - 1));
		*(tab + (size - i - 1)) = *(tab + i);
		*(tab + i) = t;
		i++;
	}
}
