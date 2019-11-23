/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:26:41 by jbowen            #+#    #+#             */
/*   Updated: 2019/11/24 00:26:45 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_makearray(t_list *l_num, int *i)
{
	int	j;
	int *array;

	j = 0;
	while (l_num->prev != NULL)
	{
		l_num = l_num->prev;
		(*i)++;
	}
	if ((array = (int *)malloc(sizeof(int) * (*i))) == NULL)
		return (NULL);
	while (j < (*i))
	{
		array[j] = l_num->value;
		j++;
		l_num = l_num->next;
	}
	quicksort(array, 0, *i - 1);
	if ((array = ft_checkrep(array, *i)) == NULL)
		return (NULL);
	return (array);
}
