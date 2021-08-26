/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 20:20:17 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/14 21:02:49 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verify_partial.h"
#include "verify.h"
#include "ft_solve.h"
#include "ft_string.h"

int	**ft_solve(int *rules, int size)
{
	int		**tab;
	int		i;

	tab = malloc(sizeof(tab) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(sizeof(int) * size);
		i++;
	}
	ft_fill(tab, size);
	ft_seed(tab, rules, size);
	if (ft_solve_rec(tab, rules, size, 0))
		return (tab);
	return (0);
}

int	ft_solve_rec(int **tab, int *rules, int size, int depth)
{
	int		i;
	int		filled;

	if (depth == size * size)
		return (verify_matrix(tab, rules, size));
	i = 0;
	filled = 0;
	while (i < size && !filled)
	{
		if (i == 0 && tab[depth / size][depth % size] != 0)
			filled = 1;
		if (!filled)
			tab[depth / size][depth % size] = i + 1;
		if (verify_partial_matrix(tab, rules, size, depth))
		{
			if (ft_solve_rec(tab, rules, size, depth + 1))
				return (1);
		}
		i++;
	}
	if (!filled)
		tab[depth / size][depth % size] = 0;
	return (0);
}

void	ft_fill(int **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
			tab[i][j++] = 0;
		i++;
	}
}

void	ft_seed(int **tab, int	*rules, int size)
{
	int		i;

	i = 0;
	while (i < size * 4)
	{
		if (i < size && rules[i] == 1)
			tab[i][0] = size;
		else if (i >= size && i < size * 2 && rules[i] == 1)
			tab[i % size][size - 1] = size;
		else if (i >= size * 2 && i < size * 3 && rules[i] == 1)
			tab[0][i % size] = size;
		else if (i >= size * 3 && rules[i] == 1)
			tab[size - 1][i % size] = size;
		i++;
	}
}
