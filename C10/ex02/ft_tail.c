#include "ft_sys.h"
#include "ft_string.h"
#include "ft_utils.h"

int		ft_read_files(char *name, char **tab, int count, int offset);
void	ft_write_name(char *file, int val);

int	ft_end_of_file(char *name, char *file, int n)
{
	int			fd;
	char		c;
	long int	size;
	long int	pos;

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error(name, file);
		return (1);
	}
	while (read(fd, &c, 1) > 0)
		size++;
	pos = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (pos++ > size - n)
			ft_putchar(c);
	close(fd);
	return (0);
}

void	ft_read_stdinp(int n)
{
	char	c;
	char	*stored;
	int		m;
	int		i;

	i = 0;
	stored = malloc(sizeof(char) * (n + 1));
	while (i <= n)
		stored[i++] = 0;
	m = 0;
	while (read(0, &c, 1))
	{
		if (n)
			ft_store(c, stored, m++, n);
	}
	if (n)
		ft_putstr(ft_read_at(stored, m, n));
}

int	main(int argc, char **argv)
{
	int		offset;

	if (argc < 3)
	{
		ft_c_error(argv[0] + 2);
		return (1);
	}
	offset = ft_mod_atoi(argv[2]);
	if (offset < 0)
	{
		ft_putstr_error(argv[0] + 2);
		ft_putstr_error(": illegal offset -- ");
		ft_putstr_error(argv[2]);
		ft_putstr_error("\n");
		return (1);
	}
	if (argc < 4)
	{
		ft_read_stdinp(offset);
		return (0);
	}
	return (ft_read_files(argv[0] + 2, argv + 3, argc - 3, offset + 1));
}

int	ft_read_files(char *name, char **tab, int count, int offset)
{
	int		i;
	int		ret;
	int		temp;

	i = 0;
	ret = 0;
	if (count < 2)
		return (ft_end_of_file(name, tab[0], offset));
	while (i < count)
	{
		temp = open(tab[i], O_RDONLY);
		if (temp < 0)
		{
			ft_error(name, tab[i++]);
			ret++;
			continue ;
		}
		close(temp);
		ft_write_name(tab[i], i - ret);
		ret += ft_end_of_file(name, tab[i], offset);
		i++;
	}
	return (ret);
}

void	ft_write_name(char *file, int val)
{
	if (val != 0)
		ft_putchar('\n');
	ft_putstr("==> ");
	ft_putstr(file);
	ft_putstr(" <==\n");
}
