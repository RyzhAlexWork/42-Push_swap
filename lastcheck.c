/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:31:36 by jbowen            #+#    #+#             */
/*   Updated: 2019/11/24 00:31:38 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int lastcheck(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->prev != NULL)
		stack_a = stack_a->prev;
	if (stack_b == NULL)
	{
		while (stack_a->next != NULL &&
			   stack_a->value < (stack_a->next)->value)
			stack_a = stack_a->next;
		if (stack_a->next == NULL &&
			(stack_a->prev)->value < stack_a->value)
		{
			write(1, "OK\n", 3);
			return (1);
		}
		else
		{
			write(1, "KO\n", 3);
			return (-1);
		}
	}
	else
	{
		write(1, "KO\n", 3);
		return (-1);
	}
}
