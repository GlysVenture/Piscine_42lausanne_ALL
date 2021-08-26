#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*range;

	if (min >= max)
		return (0);
	range = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		range[max - min - 1] = max - 1;
		max--;
	}
	return (range);
}
