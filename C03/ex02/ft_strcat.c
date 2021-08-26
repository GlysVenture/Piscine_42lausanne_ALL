char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		n;

	i = 0;
	while (*(dest + i))
		i++;
	n = i;
	i = 0;
	while (*(src + i))
		*(dest + n++) = *(src + i++);
	*(dest + n) = 0;
	return (dest);
}
