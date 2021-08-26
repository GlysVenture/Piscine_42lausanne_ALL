/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:33:06 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/07 13:04:59 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prototype
void	ft_putchar(char c);
void	ft_line(int x, char corner, char middle);

// rush function
void	rush(int x, int y)
{
	int		i;

	i = 0;
	if (y > 0)
	{
		ft_line(x, 'A', 'B');
	}
	while (i < (y - 2))
	{
		ft_line(x, 'B', ' ');
		i++;
	}
	if (y > 1)
	{
		ft_line(x, 'C', 'B');
	}
}

// line function
void	ft_line(int x, char corner, char middle)
{
	int		j;

	j = 0;
	if (x > 0)
	{
		ft_putchar(corner);
	}
	while (j < (x - 2))
	{
		ft_putchar(middle);
		j++;
	}
	if (x > 1)
	{
		ft_putchar(corner);
	}
	ft_putchar('\n');
}
