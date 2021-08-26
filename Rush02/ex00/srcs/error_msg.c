#include "error_msg.h"
#include "ft_string.h"

void	show_usage(void)
{
	ft_putstr("usage:\n\t");
	ft_putstr(EXECUTABLE_NAME);
	ft_putstr(" [dictionary_file] number\n\n");
	ft_putstr("number:\n\t");
	ft_putstr("mandatory,\n\t");
	ft_putstr("any valid unsigned integer\n\n");
	ft_putstr("dictionary_file:\n\t");
	ft_putstr("optional,\n\t");
	ft_putstr("file name of your custom defined dictionary\n\n");
	ft_putstr("additional info:\n\t");
	ft_putstr("we <3 the bocal, so give us max points!\n");
}

int	error_msg(char msg)
{
	if (msg == INVALID_ARG_COUNT)
		show_usage();
	if (msg == INVALID_INT_INPUT || msg == CANNOT_CONVERT_INT)
		ft_putstr("Error");
	if (msg == DICT_ERROR)
		ft_putstr("Dict Error");
	ft_putstr("\n");
	return (0);
}
