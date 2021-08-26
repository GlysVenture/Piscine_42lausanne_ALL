#include "ft_utils.h"
#include "ft_string.h"
#include "ft_sys.h"

int	ft_mod_atoi(char *str)
{
	int			i;
	long int	numb;

	i = 0;
	numb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = 10 * numb + (str[i] - '0');
		i++;
	}
	if (!str[i] && i)
		return (numb);
	return (-1);
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

void	ft_c_error(char *name)
{
	ft_putstr(name);
	ft_putstr(": option requires an argument -- c\n");
	ft_putstr("usage: tail [-F | -f | -r] ");
	ft_putstr("[-q] [-b # | -c # | -n #] [file ...]\n");
}
