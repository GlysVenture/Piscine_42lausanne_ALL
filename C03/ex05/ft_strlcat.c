unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	m;

	i = 0;
	m = 0;
	while (*(dest + m))
		m++;
	while ((i + 1 + m) < size && *(src + i))
	{
		*(dest + m + i) = *(src + i);
		i++;
	}
	if ((m + 1) <= size)
		*(dest + m + i) = 0;
	while (*(src + i))
		i++;
	if (size < m)
		return (size + i);
	return (m + i);
}
