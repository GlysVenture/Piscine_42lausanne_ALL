/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:20:23 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/09 19:16:44 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_char_hex(char c, char *h);

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	h[3];

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) < 32) || *(str + i) > 126)
		{
			ft_char_hex(*(str + i), h);
			write(1, h, 3);
		}
		else
			write(1, str + i, 1);
		i++;
	}
}

void	ft_char_hex(char c, char *h)
{
	int		i;

	i = c;
	if (i < 0)
		i = 256 + i;
	h[0] = 92;
	if ((i % 16) > 9)
		h[2] = (i % 16) + 87;
	else
		h[2] = (i % 16) + 48;
	if ((i / 16) > 9)
		h[1] = (i / 16) + 87;
	else
		h[1] = (i / 16) + 48;
}
