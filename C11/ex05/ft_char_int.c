#include "ft_char_int.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		if ((nb / 10) != 0)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + (nb % 10));
	}
}

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long int	numb;

	i = 0;
	numb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		   || str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = 10 * numb + (str[i] - '0');
		i++;
	}
	return (sign * numb);
}
