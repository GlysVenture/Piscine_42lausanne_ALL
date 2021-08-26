#include <unistd.h>

void	ft_print(int *free)
{
	if (*free)
	{
		*free = 0;
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	num[3];
	int		first;

	num[0] = '0';
	first = 1;
	while (num[0] < '8')
	{
		num[1] = num[0] + 1;
		while (num[1] < '9')
		{
			num[2] = num[1] + 1;
			while (num[2] < 58)
			{
				ft_print(&first);
				write(1, &num, 3);
				num[2]++;
			}
			num[1]++;
		}
		num[0]++;
	}
}
