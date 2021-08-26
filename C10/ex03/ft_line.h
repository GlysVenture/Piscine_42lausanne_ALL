#ifndef FT_LINE_H
# define FT_LINE_H

# include "line_struct.h"
void	ft_print(char *line, int offset, int end, int c);
char	*ft_char_hex(char c);
void	ft_print_printable(char *line, int len);
void	ft_print_hex(char *line, int len, int c);
void	print_line(t_line *lines, int *first, int j, int c);

#endif
