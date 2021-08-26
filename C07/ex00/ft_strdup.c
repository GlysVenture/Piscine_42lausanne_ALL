#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = malloc(sizeof(*src) * (i + 1));
	i = 0;
	while (src[i])
	{
		*(dup + i) = src[i];
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}
