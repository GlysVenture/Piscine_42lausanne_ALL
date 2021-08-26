#include <unistd.h>

char	*ft_strstr(char *str, char *to_find);

//recursive printing in given base
void	ft_putnbr_recbase(long int nb, char *base, int size)
{	
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_recbase(-nb, base, size);
	}
	else
	{
		if ((nb / size) != 0)
		{
			ft_putnbr_recbase(nb / size, base, size);
		}
		write(1, base + (nb % size), 1);
	}
}

//ft_nbr checks error bases, counts size and launches recursive printing
void	ft_putnbr_base(int nbr, char *base)
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
	ft_putnbr_recbase(nbr, base, i);
	return ;
}

//ft_strcmp to compare strings
int	static	ft_next_strncmp(char *s1, char *s2, unsigned int l, unsigned int m)
{
	if ((*s1 == '\0' && *s2 == '\0') || l >= m)
		return (0);
	else if ((*s1 - *s2) != 0)
		return (*s1 - *s2);
	else
		return (ft_next_strncmp(s1 + 1, s2 + 1, l + 1, m));
}

int	ft_strncmp(char *s1, char *s2, unsigned int m)
{
	return (ft_next_strncmp(s1, s2, 0, m));
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
