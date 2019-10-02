/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:45:43 by jbowen            #+#    #+#             */
/*   Updated: 2019/05/14 15:32:39 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_negat(int n, char *str)
{
	int		ret;

	ret = n;
	if (ret == -2147483648)
	{
		ret = 147483648;
		str[0] = '-';
		str[1] = '2';
		str[2] = '\0';
	}
	if (ret < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		return (ret / -1);
	}
	else
		return (ret);
}

static	size_t	ft_numdig(int n)
{
	size_t	i;
	size_t	del;

	i = 1;
	del = 10;
	if (n == -2147483648)
	{
		n = 147483648;
		i++;
	}
	if (n < 0)
	{
		n = n / -1;
		i++;
	}
	while (n / del != 0)
	{
		del = del * 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	del;
	size_t	i;
	int		ret;
	char	*str;

	i = ft_numdig(n);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	del = 10;
	ret = ft_negat(n, str);
	while (ret / del != 0)
		del = del * 10;
	del = del / 10;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (del != 0)
	{
		str[i] = (((ret % (del * 10)) / del) + '0');
		del = del / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
