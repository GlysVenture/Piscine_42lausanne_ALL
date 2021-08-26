int	ft_iterative_power(int nb, int power)
{
	int		f;

	f = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 0)
	{
		f = f * nb;
		power--;
	}
	return (f);
}
