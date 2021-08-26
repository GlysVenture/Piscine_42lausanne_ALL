void	ft_capitalize(char *c);
void	ft_lower(char *c);
int		is_alpha_numeric(char c);

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (*(str + i) != '\0')
	{
		if (!a && is_alpha_numeric(*(str + i)))
		{
			ft_capitalize(str + i);
			a = 1;
		}
		else if (is_alpha_numeric(*(str + i)))
		{
			a = 1;
			ft_lower(str + i);
		}
		else
			a = 0;
		i++;
	}
	return (str);
}

void	ft_capitalize(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c = *c - 32;
	}
}

void	ft_lower(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
	{
		*c = *c + 32;
	}
}

int	is_alpha_numeric(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
