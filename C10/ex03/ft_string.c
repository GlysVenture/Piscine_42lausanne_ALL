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

int	ft_strncmp(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = -1;
	while (++i < n)
		dest[i] = src[i];
	return (dest);
}

void	ft_putstr_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}
