#ifndef FT_SOLVE_H
# define FT_SOLVE_H

# include <stdlib.h>
int		**ft_solve(int *rules, int size);
int		ft_solve_rec(int **tab, int *rules, int size, int depth);
void	ft_fill(int **tab, int size);
void	ft_seed(int **tab, int *rules, int size);

#endif
