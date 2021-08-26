#include <unistd.h>
#include "ft_string.h"

char	*ft_strstr(char *str, char *to_find);

//recursive printing in given base (modified)
void	ft_putnbr_recbase(long int nb, char *base, int size, int depth)
{	
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_recbase(-nb, base, size, depth);
	}
	else
	{
		if (depth < 8)
		{
			ft_putnbr_recbase(nb / size, base, size, depth + 1);
		}
		write(1, base + (nb % size), 1);
	}
}

//ft_nbr checks error bases, counts size and launches recursive printing
void	ft_putnbr_base(int nbr, char *base, int is_c)
{
	int		i;
	char	c[1];

	i = 0;
	while (base[i])
	{
		c[0] = base[i];
		if (ft_strstr(base + i + 1, c))
			return ;
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (i <= 1)
		return ;
	if (is_c)
		ft_putnbr_recbase(nbr, base, i, 1);
	else
		ft_putnbr_recbase(nbr, base, i, 2);
	return ;
}

//ft_strstr to find strings
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (*(to_find + i))
		i++;
	if (!i)
		return (str);
	while (*(str + j))
	{
		if (!ft_strncmp(str + j, to_find, i))
			return (str + j);
		j++;
	}
	return (0);
}
