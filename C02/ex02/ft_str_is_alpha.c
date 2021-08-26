int	ft_str_is_alpha(char *str)
{
	int		i;
	int		a;

	i = 0;
	while (*(str + i) != '\0')
	{
		a = ((*(str + i) < 'A') || (*(str + i) > 'Z'));
		if (a && ((*(str + i) < 'a') || (*(str + i) > 'z')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
