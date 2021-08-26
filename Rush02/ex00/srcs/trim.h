#ifndef TRIM_H
# define TRIM_H

/* ************************************************************************** */
/* str is the argv that contains the number to be converted					  */
/* ************************************************************************** */
void	trim_leading_whitespaces(char *str);
void	trim_trailing_whitespaces(char *str);
void	trim_leading_zeroes(char *str);

/* ************************************************************************** */
/* str points to the - sign if found; if following chars are 0, returns true  */
/* ************************************************************************** */
int		is_zero(char *str);

#endif
