#include "ft_line.h"
#include "ft_string.h"
#include "ft_putnbr_base.h"
#include <stdlib.h>
#include "line_struct.h"

void	ft_print(char *line, int offset, int end, int c)
{
	char	*base;

	base = "0123456789abcdef\0";
	if (!offset || (offset % 16 == 0 && end))
		return ;
	if (line == NULL)
	{
		ft_putnbr_base(offset, base, c);
		ft_putchar('\n');
		return ;
	}
	if (offset % 16 == 0)
		ft_putnbr_base(offset - 16, base, c);
	else
		ft_putnbr_base(offset - (offset % 16), base, c);
	if (c)
		ft_putchar(' ');
	ft_putchar(' ');
	ft_print_hex(line, offset % 16, c);
	if (c)
	{
		ft_putstr("  ");
		ft_print_printable(line, offset % 16);
	}
	ft_putchar('\n');
}

void	ft_print_hex(char *line, int len, int c)
{
	int		i;
	char	*str;

	i = 0;
	if (len == 0)
		len = 16;
	while (i < len)
	{
		str = ft_char_hex(line[i]);
		ft_putstr(str);
		if (i == 7 && c)
			ft_putchar(' ');
		if (i != len - 1)
			ft_putchar(' ');
		free(str);
		i++;
	}
	if (i <= 7 && c)
		ft_putchar(' ');
	while (i++ < 16)
		ft_putstr("   ");
}

char	*ft_char_hex(char c)
{
	int		i;
	char	*h;

	h = malloc(sizeof(char) * 3);
	h[2] = 0;
	i = c;
	if (i < 0)
		i = 256 + i;
	if ((i % 16) > 9)
		h[1] = (i % 16) + 87;
	else
		h[1] = (i % 16) + 48;
	if ((i / 16) > 9)
		h[0] = (i / 16) + 87;
	else
		h[0] = (i / 16) + 48;
	return (h);
}

void	ft_print_printable(char *line, int len)
{
	int		i;

	i = -1;
	if (len == 0)
		len = 16;
	ft_putchar('|');
	while (++i < len)
	{
		if (line[i] < 32 || line[i] > 126)
			ft_putchar('.');
		else
			ft_putchar(line[i]);
	}
	ft_putchar('|');
}

void	print_line(t_line *lines, int *first, int j, int c)
{
	if (ft_strncmp(lines->line, lines->old, 16))
	{
		ft_print(lines->line, j, 0, c);
		*first = 1;
	}
	else if (*first)
	{
		ft_putstr("*\n");
		*first = 0;
	}
	ft_strncpy(lines->old, lines->line, 16);
}
