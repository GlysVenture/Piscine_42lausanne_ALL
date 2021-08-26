#include "ft_print.h"

void	ft_print(int **tab, int size)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (i < (size - 1))
				write(1, " ", 1);
			i++;
		}
		j++;
		write(1, "\n", 1);
	}	
}
