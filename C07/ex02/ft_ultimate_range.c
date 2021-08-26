#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		size;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	size = max - min;
	while (min < max)
	{
		(*range)[max - min - 1] = max - 1;
		max--;
	}
	return (size);
}
