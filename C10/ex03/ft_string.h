#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_putstr_error(char *str);

#endif
