/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:16:37 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/10 17:19:11 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	static	ft_next_strncmp(char *s1, char *s2, unsigned int l, unsigned int m)
{
	if ((*s1 == '\0' && *s2 == '\0') || l >= m)
		return (0);
	else if ((*s1 - *s2) != 0)
		return (*s1 - *s2);
	else
		return (ft_next_strncmp(s1 + 1, s2 + 1, l + 1, m));
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	return (ft_next_strncmp(s1, s2, 0, n));
}
