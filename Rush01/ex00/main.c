#include <stdlib.h>
#include "ft_string.h"
#include "ft_rules.h"
#include "ft_print.h"
#include "ft_solve.h"
#include "verify.h"

void	ft_error(void);

int	main(int argc, char **argv)
{
	int		size;
	int		*rules;
	int		**solution;

	if (argc != 2)
	{
		ft_error();
		return (0);
	}
	size = ft_count(argv[1]);
	if (size <= 0)
	{
		ft_error();
		return (0);
	}
	rules = ft_store_rules(argv[1], size);
	solution = ft_solve(rules, size);
	if (verify_matrix(solution, rules, size))
		ft_print(solution, size);
	else
		ft_error();
	free(solution);
	free(rules);
	return (0);
}

// ecrit Error et un retour a la ligne
void	ft_error(void)
{
	ft_putstr("Error");
	ft_putchar('\n');
}
