#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "ft_string.h"
#include <sys/errno.h>
#include <string.h>

int	ft_display_file(char *name, char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (errno)
	{
		ft_putstr_error(name);
		ft_putstr_error(": ");
		ft_putstr_error(file);
		ft_putstr_error(": ");
		ft_putstr_error(strerror(errno));
		ft_putstr_error("\n");
		errno = 0;
		return (1);
	}
	while (read(fd, &c, 1) > 0)
		ft_putchar(c);
	close(fd);
	return (0);
}

void	ft_read_stdinp(void)
{
	char	c;

	while (read(0, &c, 1))
		ft_putchar(c);
}

int	main(int argc, char **argv)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if (argc < 2)
	{
		ft_read_stdinp();
		return (0);
	}
	while (i < argc)
	{
		if (argv[i][0] == '-' && !argv[i][1])
			ft_read_stdinp();
		else
			ret += ft_display_file(argv[0] + 2, argv[i]);
		i++;
	}
	return (ret);
}
