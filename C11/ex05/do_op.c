#include "ft_op.h"
#include "ft_char_int.h"

typedef void	(*t_f_op)(int, int);

t_f_op	ft_get_op(char *op);

int	main(int argc, char **argv)
{
	void	(*op)(int, int);
	int		a;
	int		b;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	op = ft_get_op(argv[2]);
	b = ft_atoi(argv[3]);
	if (!op)
	{
		ft_putstr("0\n");
		return (0);
	}
	(*op)(a, b);
	return (0);
}

t_f_op	ft_get_op(char *op)
{
	if (!op[0] || op[1])
		return (0);
	if (op[0] == '+')
		return (&ft_sum);
	else if (op[0] == '-')
		return (&ft_substract);
	else if (op[0] == '/')
		return (&ft_div);
	else if (op[0] == '%')
		return (&ft_mod);
	else if (op[0] == '*')
		return (&ft_multiply);
	else
		return (0);
}
