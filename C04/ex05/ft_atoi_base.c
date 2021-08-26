/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:42:00 by tkondrac          #+#    #+#             */
/*   Updated: 2021/08/11 17:38:20 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_to_num(char c, char *base);

// checks if base is free from errors and returns length
int	ft_check_base(char *base)
{
	int		i;
	char	c;

	i = 0;
	while (base[i])
	{
		c = base[i];
		if (ft_base_to_num(c, base + i + 1) > 0)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

//finds place where c character is in base, or returns -1 otherwise
int	ft_base_to_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// gets sign and traverses spaces and + -
int	ft_get_sign(char *str, int *i)
{
	int		sign;

	sign = 1;
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t'
		|| str[*i] == '\f' || str[*i] == '\v' || str[*i] == '\r')
		*i = *i + 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1 * sign;
		*i = *i + 1;
	}
	return (sign);
}

//reads number in given base and returns int value
int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	long int	numb;
	int			len;

	i = 0;
	numb = 0;
	sign = 1;
	len = ft_check_base(base);
	if (!len)
		return (0);
	sign = ft_get_sign(str, &i);
	while (ft_base_to_num(str[i], base) >= 0)
	{
		numb = len * numb + ft_base_to_num(str[i], base);
		i++;
	}
	return (sign * numb);
}
