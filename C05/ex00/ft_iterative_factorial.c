/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:07:55 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/12 12:11:34 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		f;

	f = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
		f = f * nb--;
	return (f);
}
