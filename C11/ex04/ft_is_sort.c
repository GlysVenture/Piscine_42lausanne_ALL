int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		d;

	i = 1;
	d = 0;
	if (!tab)
		return (1);
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
		{
			if (d < 0)
				return (0);
			d = 1;
		}
		if ((*f)(tab[i - 1], tab[i]) < 0)
		{
			if (d > 0)
				return (0);
			d = -1;
		}
		i++;
	}
	return (1);
}
