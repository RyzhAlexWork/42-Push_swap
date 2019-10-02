/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:05:03 by jbowen            #+#    #+#             */
/*   Updated: 2019/05/13 21:26:57 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	j = len;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (j > 0 && dst > src)
	{
		str1[j - 1] = str2[j - 1];
		j--;
	}
	while (i < len && dst < src)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
