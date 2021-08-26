int	ft_check_prime(int nb, long int i)
{
	if (i * i > nb)
		return (1);
	else if (nb % i == 0)
		return (0);
	return (ft_check_prime(nb, i + 1));
}

int	ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	return (ft_check_prime(nb, 2));
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
