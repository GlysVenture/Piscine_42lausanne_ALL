#ifndef VERIFY_PARTIAL_H
# define VERIFY_PARTIAL_H
# include<stdlib.h>
# include "verify.h"

int	verify_partial_matrix(int **matrix, int *rules, int n, int depth);
int	ft_power(int power);
int	check_array_numbers_partial(int *array, int n, int x);
int	check_rules_partial(int *array, int rule, int n);
int	check_rules_partial_rev(int *array, int rule, int n);
int	check_array_n_partial_row(int **matrix, int nrow, int n, int x);
int	check_r_partial_row(int **array, int nrow, int rule, int n);
int	check_r_partial_row_rev(int **array, int nrow, int rule, int n);

#endif
