#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
