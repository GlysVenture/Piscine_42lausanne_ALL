char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	int					m;

	i = 0;
	m = 0;
	while (*(dest + m))
		m++;
	while (i < nb && *(src + i))
		*(dest + m++) = *(src + i++);
	*(dest + m) = 0;
	return (dest);
}
