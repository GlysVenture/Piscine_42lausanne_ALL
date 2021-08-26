#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_store(char c, char *storage, int m, int n);
char	*ft_read_at(char *storage, int m, int n);
void	ft_putstr_error(char *str);

#endif
