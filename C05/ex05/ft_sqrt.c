int	ft_check_sq(int nb, long int i)
{
	if (i * i > nb)
		return (0);
	else if (i * i == nb)
		return (i);
	return (ft_check_sq(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	if (nb < 1)
		return (0);
	return (ft_check_sq(nb, 1));
}
