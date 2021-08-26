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
