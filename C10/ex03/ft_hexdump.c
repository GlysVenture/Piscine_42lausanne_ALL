#include "ft_string.h"
#include "ft_sys.h"
#include "ft_line.h"
#include "line_struct.h"

void	ft_read_files(char *name, char **tab, int count, int c);
void	ft_error(char *name, char *file);
void	ft_std_inp(int c);
int		ft_open_file(char *name, char *file, int *fd);

int	main(int argc, char **argv)
{
	int		is_c;

	is_c = 0;
	if (argc < 2)
	{
		ft_std_inp(is_c);
		return (0);
	}
	else if (argv[1][0] == '-' && argv[1][1] == 'C' && !argv[1][2])
		is_c = 1;
	if (argc < 3 && is_c)
	{
		ft_std_inp(is_c);
		return (0);
	}
	ft_read_files(argv[0] + 2, argv + 1 + is_c, argc - 1 - is_c, is_c);
}

void	ft_read_files(char *name, char **tab, int count, int c)
{
	int		i;
	int		j;
	int		fd;
	t_line	lines;
	int		first;

	i = -1;
	j = 0;
	fd = -1;
	first = 0;
	while (++i < count)
	{
		if (ft_open_file(name, tab[i], &fd))
		{
			while (read(fd, lines.line + (j % 16), 1))
			{
				if (++j % 16 == 0)
					print_line(&lines, &first, j, c);
			}
		}
	}
	if (0 > close(fd))
		ft_error(name, tab[i - 1]);
	ft_print(lines.line, j, 1, c);
	ft_print(NULL, j, 0, c);
}

void	ft_error(char *name, char *file)
{
	ft_putstr_error(name);
	ft_putstr_error(": ");
	ft_putstr_error(file);
	ft_putstr_error(": ");
	ft_putstr_error(strerror(errno));
	ft_putstr_error("\n");
	errno = 0;
}

void	ft_std_inp(int c)
{
	int		j;
	t_line	lines;
	int		first;

	j = 0;
	first = 0;
	while (read(0, lines.line + (j % 16), 1))
	{
		j++;
		if (j % 16 == 0)
			print_line(&lines, &first, j, c);
	}
	ft_print(lines.line, j, 1, c);
	ft_print(NULL, j, 0, c);
}

int	ft_open_file(char *name, char *file, int *fd)
{
	int		temp;

	temp = open(file, O_RDONLY);
	if (temp < 0)
	{
		ft_error(name, file);
		return (0);
	}
	close(*fd);
	*fd = temp;
	return (1);
}
