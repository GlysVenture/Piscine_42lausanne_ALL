#include "ft_op.h"
#include "ft_char_int.h"
#include <unistd.h>

void	ft_div(int a, int b)
{
	int		res;

	if (b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	res = a / b;
	ft_putnbr(res);
	ft_putchar('\n');
}

void	ft_mod(int a, int b)
{
	int		res;

	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	res = a % b;
	ft_putnbr(res);
	ft_putchar('\n');
}

void	ft_sum(int a, int b)
{
	int		res;

	res = a + b;
	ft_putnbr(res);
	ft_putchar('\n');
}

void	ft_substract(int a, int b)
{
	int		res;

	res = a - b;
	ft_putnbr(res);
	ft_putchar('\n');
}

void	ft_multiply(int a, int b)
{
	int		res;

	res = a * b;
	ft_putnbr(res);
	ft_putchar('\n');
}
