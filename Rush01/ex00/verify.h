#ifndef VERIFY_H
# define VERIFY_H
# include<stdlib.h>

int	verify_matrix(int **matrix, int *rules, int n);
int	*extract_row(int **matrix, int nrow, int n);
int	check_array_numbers(int *array, int n);
int	check_rules(int *array, int r1, int r2, int n);

#endif
