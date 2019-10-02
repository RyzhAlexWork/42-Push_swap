/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:58:39 by jbowen            #+#    #+#             */
/*   Updated: 2019/05/03 16:43:28 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char dig, char sign, long int res)
{
	if ((sign == '+' && res > 223372036854775807) ||
			(res == 223372036854775807 && dig == 7))
		return (-1);
	if ((sign == '-' && res < -223372036854775806) ||
			(res == -223372036854775806 && dig == 6))
		return (0);
	else
		return (10);
}

static int	ft_result(const char *dig)
{
	size_t		i;
	long int	res;
	char		sign;

	i = 0;
	res = 0;
	sign = '+';
	if (dig[i] == '+' || dig[i] == '-')
	{
		sign = dig[i];
		i++;
	}
	while (ft_isdigit(dig[i]))
	{
		if (ft_check(dig[i], sign, res) == -1
				|| ft_check(dig[i], sign, res) == 0)
			return (ft_check(dig[i], sign, res));
		if (sign == '-')
			res = res * 10 - (dig[i] - '0');
		else
			res = res * 10 + (dig[i] - '0');
		i++;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	size_t		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (ft_result(str + i));
}
