/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:22:32 by jbowen            #+#    #+#             */
/*   Updated: 2019/04/20 12:37:06 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	save;

	i = 0;
	j = 0;
	save = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		save = i;
		while (haystack[i] == needle[j] && haystack[i] != '\0')
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + save));
			i++;
			j++;
		}
		i = save + 1;
		j = 0;
	}
	return (NULL);
}
