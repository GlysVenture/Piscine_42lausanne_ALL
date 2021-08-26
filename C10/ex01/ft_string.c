#include "ft_string.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putstr_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
