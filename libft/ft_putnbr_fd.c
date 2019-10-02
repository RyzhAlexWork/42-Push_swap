/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:56:53 by jbowen            #+#    #+#             */
/*   Updated: 2019/04/20 17:26:10 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negat(int n, int fd)
{
	int	ret;

	ret = n;
	if (ret == -2147483648)
	{
		ret = 147483648;
		ft_putstr_fd("-2", fd);
	}
	if (ret < 0)
	{
		ft_putchar_fd('-', fd);
		return (ret / -1);
	}
	else
		return (ret);
}

void		ft_putnbr_fd(int n, int fd)
{
	size_t	del;
	int		ret;

	del = 10;
	ret = ft_negat(n, fd);
	while (ret / del != 0)
		del = del * 10;
	del = del / 10;
	while (del != 0)
	{
		ft_putchar_fd((((ret % (del * 10)) / del) + '0'), fd);
		del = del / 10;
	}
}
