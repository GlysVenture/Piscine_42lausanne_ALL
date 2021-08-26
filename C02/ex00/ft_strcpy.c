/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:46:56 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/08 16:18:03 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	*dest = *src;
	while (*(src + i) != '\0')
	{
		i++;
		*(dest + i) = *(src + i);
	}
	return (dest);
}
