#include "ft_string.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_store(char c, char *storage, int m, int n)
{
	storage[m % n] = c;
}

char	*ft_read_at(char *storage, int m, int n)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	out = malloc(sizeof(char) * (n + 1));
	while (i <= n)
		out[i++] = 0;
	i = m % n;
	j = 0;
	while (storage[i])
		out[j++] = storage[i++];
	i = 0;
	while (i < m % n)
		out[j++] = storage[i++];
	return (out);
}

void	ft_putstr_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}
