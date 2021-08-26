int	ft_is_sort(char **tab, int (*f)(char*, char*));

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	void	*temp;

	if (!tab)
		return ;
	while (!ft_is_sort(tab, cmp))
	{
		i = 1;
		while (tab[i])
		{
			if ((*cmp)(tab[i - 1], tab[i]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
			}
			i++;
		}
	}
}

int	ft_is_sort(char **tab, int (*f)(char*, char*))
{
	int		i;

	i = 1;
	if (!tab[0])
		return (1);
	while (tab[i])
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}
