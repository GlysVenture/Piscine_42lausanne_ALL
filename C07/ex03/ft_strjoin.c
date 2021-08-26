#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// modified strcat doesnt return char
void	ft_strcat(char *dest, char *src)
{
	int		i;
	int		n;

	n = 0;
	while (*(dest + n))
		n++;
	i = 0;
	while (*(src + i))
		*(dest + n++) = *(src + i++);
	*(dest + n) = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		char_nb;

	if (size <= 0 || strs == NULL)
	{
		dest = malloc(sizeof(char));
		return (0);
	}
	i = 0;
	char_nb = -ft_strlen(sep);
	while (i < size)
		char_nb = char_nb + ft_strlen(strs[i++]) + ft_strlen(sep);
	dest = malloc(sizeof(char) * (char_nb + 1));
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(dest, strs[i]);
		ft_strcat(dest, sep);
		i++;
	}
	ft_strcat(dest, strs[i]);
	return (dest);
}
