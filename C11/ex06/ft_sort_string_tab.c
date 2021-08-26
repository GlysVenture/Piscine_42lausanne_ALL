int	ft_is_sort(char **tab, int (*f)(char*, char*));
int	ft_strcmp(char *s1, char *s2);

void	ft_sort_string_tab(char **tab)
{
	int		i;
	void	*temp;

	if (!tab)
		return ;
	while (!ft_is_sort(tab, &ft_strcmp))
	{
		i = 1;
		while (tab[i])
		{
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
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

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
