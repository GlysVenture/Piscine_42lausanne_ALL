#include <stdlib.h>

int		ft_count_size(char *str, char *charset);
int		ft_find_char(char c, char *base);
char	*ft_strndup(char *src, int n);
void	ft_tab_fill(char *str, char *charset, char **tab);

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**tab;

	size = ft_count_size(str, charset);
	tab = malloc(sizeof(*tab) * (size + 1));
	if (tab == NULL)
		return (0);
	while (size >= 0)
		tab[size--] = 0;
	ft_tab_fill(str, charset, tab);
	return (tab);
}

void	ft_tab_fill(char *str, char *charset, char **tab)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (str[i])
	{
		len = i;
		while (str[i] && (ft_find_char(str[i], charset) < 0))
			i++;
		if (i - len)
		{
			tab[j] = ft_strndup(str + len, i - len);
			if (tab[j++] == NULL)
			{
				tab = 0;
				return ;
			}
		}
		else
			i++;
	}
	tab[j] = 0;
}

int	ft_count_size(char *str, char *charset)
{
	int		i;
	int		str_nb;
	int		wasSep;

	i = 0;
	wasSep = 1;
	str_nb = 0;
	while (str[i])
	{
		if (ft_find_char(str[i], charset) >= 0 && !wasSep)
		{
			str_nb++;
			wasSep = 1;
		}
		else if (ft_find_char(str[i], charset) >= 0)
			wasSep = 1;
		else
			wasSep = 0;
		i++;
	}
	if (!wasSep && i)
		str_nb++;
	return (str_nb);
}

int	ft_find_char(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i] && i < n)
		i++;
	dup = malloc(sizeof(*src) * (i + 1));
	if (dup == NULL)
		return (0);
	i = 0;
	while (src[i] && i < n)
	{
		*(dup + i) = src[i];
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}
