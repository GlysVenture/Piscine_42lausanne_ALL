/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:34:46 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/08 19:21:40 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if ((*s1 - *s2) != 0)
		return (*s1 - *s2);
	else
		return (ft_strcmp(s1 + 1, s2 + 1));
}
