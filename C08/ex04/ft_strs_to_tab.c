/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:14:26 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/16 15:56:05 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stab;

	i = 0;
	if (ac < 0)
		ac = 0;
	stab = malloc (sizeof(*stab) * (ac + 1));
	if (stab == NULL)
		return (NULL);
	while (i < ac)
	{
		stab[i].size = ft_strlen(av[i]);
		stab[i].str = av[i];
		stab[i].copy = ft_strdup(stab[i].str);
		i++;
	}
	stab[i].size = 0;
	stab[i].str = 0;
	stab[i].copy = 0;
	return (stab);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = malloc(sizeof(*src) * (i + 1));
	i = 0;
	while (src[i])
	{
		*(dup + i) = src[i];
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
