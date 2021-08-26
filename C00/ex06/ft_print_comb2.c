#include <unistd.h>

void	ft_write(int first, char *num);
void	ft_step(char *num);
void	ft_boucle_hundred(int *first, char *num);

void	ft_print_comb2(void)
{
	char	num[4];
	int		first;

	first = 0;
	num[0] = '0';
	num[1] = '0';
	num[2] = '0';
	num[3] = '1';
	while (num[0] <= '9')
	{
		while (num[1] <= '9')
		{
			ft_boucle_hundred(&first, num);
			num[1]++;
			ft_step(num);
		}
		num[1] = '0';
		num[0]++;
		num[3]++;
	}
}

void	ft_boucle_hundred(int *first, char *num)
{
	while (num[2] <= '9')
	{
		while (num[3] <= '9')
		{
			ft_write(*first, num);
			*first = 1;
			num[3]++;
		}
		num[3] = '0';
		num[2]++;
	}
}

void	ft_write(int first, char *num)
{
	if (first)
	{
		write(1, ", ", 2);
	}
	write(1, num, 2);
	write(1, " ", 1);
	write(1, num + 2, 2);
}

void	ft_step(char *num)
{
	if (num[1] > '8')
	{
		num[2] = num[0] + 1;
		num[3] = '0';
	}
	else
	{
		num[2] = num[0];
		num[3] = num[1] + 1;
	}
}
