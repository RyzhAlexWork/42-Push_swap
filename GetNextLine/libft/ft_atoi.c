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
	if ((sign == '+' && res > 214748364) ||
			(res == 214748364 && dig > '7'))
		return (0);
	if ((sign == '-' && res < -214748364) ||
			(res == -214748364 && dig > '8'))
		return (0);
	else
		return (10);
}

static int	ft_result(const char *dig, int *j)
{
	int			i;
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
		if (ft_check(dig[i], sign, res) == 0)
			return (0);
		if (sign == '-')
			res = res * 10 - (dig[i] - '0');
		else
			res = res * 10 + (dig[i] - '0');
		i++;
	}
	*j = *j + i;
	return (res);
}

int			ft_atoi(const char *str, int *i)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	return (ft_result(str + *i, i));
}
