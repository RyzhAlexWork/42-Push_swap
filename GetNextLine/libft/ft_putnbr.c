/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:17:40 by jbowen            #+#    #+#             */
/*   Updated: 2019/04/20 17:26:47 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negat(int n)
{
	int	ret;

	ret = n;
	if (ret == -2147483648)
	{
		ret = 147483648;
		ft_putstr("-2");
	}
	if (ret < 0)
	{
		ft_putchar('-');
		return (ret / -1);
	}
	else
		return (ret);
}

void		ft_putnbr(int n)
{
	size_t	del;
	int		ret;

	del = 10;
	ret = ft_negat(n);
	while (ret / del != 0)
		del = del * 10;
	del = del / 10;
	while (del != 0)
	{
		ft_putchar((((ret % (del * 10)) / del) + '0'));
		del = del / 10;
	}
}
