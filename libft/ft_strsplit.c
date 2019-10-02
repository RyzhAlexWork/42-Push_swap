/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:45:16 by jbowen            #+#    #+#             */
/*   Updated: 2019/05/14 06:46:45 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_sumword(char const *str, char c)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (sum);
		while (str[i] != c && str[i] != '\0')
			i++;
		sum++;
	}
	return (sum);
}

static	char	*ft_lenword(char const *str, char c, char *s1)
{
	size_t	i;
	size_t	sum;
	size_t	j;

	i = 0;
	sum = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	j = i;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		sum++;
	}
	i = 0;
	if ((s1 = ft_strnew(sum)) == NULL)
		return (0);
	while (i < sum)
	{
		s1[i] = str[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

static	char	**ft_free(char **s2, size_t i)
{
	size_t l;

	l = 0;
	while (l <= i)
	{
		free(s2[l]);
		l++;
	}
	free(s2);
	s2 = NULL;
	return (s2);
}

static	size_t	ft_size(char const *s, char c)
{
	size_t	sum;

	sum = 0;
	while (s[sum] != '\0' && s[sum] == c)
		sum++;
	return (sum);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*s1;
	char	**s2;
	size_t	i;
	size_t	j;
	size_t	sum;

	i = 0;
	sum = 0;
	s1 = NULL;
	if (s == NULL)
		return (NULL);
	j = ft_sumword(s, c);
	if (j > j + 1)
		return (NULL);
	if ((s2 = (char **)malloc(sizeof(char *) * (j + 1))) == NULL)
		return (NULL);
	while (i < j)
	{
		if ((s2[i] = ft_lenword(s + sum, c, s1)) == NULL)
			return (ft_free(s2, i));
		sum = sum + ft_size((s + sum), c) + ft_strlen(s2[i]) + 1;
		i++;
	}
	s2[i] = NULL;
	return (s2);
}
