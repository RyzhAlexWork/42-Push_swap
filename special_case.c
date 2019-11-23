/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:28:41 by jbowen            #+#    #+#             */
/*   Updated: 2019/11/24 00:28:43 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_for_four(t_list **stack_a, t_list **stack_b, t_main *l_main)
{
	int i;

	i = 0;
	while (i < 1)
	{
		if ((*stack_a)->order < l_main->next + 1)
		{
			ft_push_b(stack_a, stack_b);
			i++;
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rotate_a(stack_a);
			write(1, "ra\n", 3);
		}
	}
	case_for_three(stack_a, l_main->next);
	ft_push_a(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	case_for_three2(t_list **stack_a, t_list *tmp, int i)
{
	if ((*stack_a)->order == 2 + i && tmp->order == 3 + i)
	{
		ft_revrotate_a(stack_a);
		write(1, "rra\n", 4);
	}
	else if ((*stack_a)->order == 3 + i && tmp->order == 1 + i)
	{
		ft_rotate_a(stack_a);
		write(1, "ra\n", 3);
	}
	else if ((*stack_a)->order == 3 + i && tmp->order == 2 + i)
	{
		ft_swap_a(stack_a);
		ft_revrotate_a(stack_a);
		write(1, "sa\nrra\n", 7);
	}
}

void	case_for_three(t_list **stack_a, int i)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	if ((*stack_a)->order == 1 + i && tmp->order == 2 + i)
		return;
	else if ((*stack_a)->order == 1 + i)
	{
		ft_revrotate_a(stack_a);
		ft_swap_a(stack_a);
		write(1, "rra\nsa\n", 7);
	}
	else if ((*stack_a)->order == 2 + i && tmp->order == 1 + i)
	{
		ft_swap_a(stack_a);
		write(1, "sa\n", 3);
	}
	case_for_three2(stack_a, tmp, i);
}

void	case_for_two(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	if ((*stack_a)->order > tmp->order)
	{
		ft_rotate_a(stack_a);
		write(1, "ra\n", 3);
	}
}

void	special_case(t_list **stack_a, t_list **stack_b, int i, t_main *l_main)
{
	if (i == 2)
		case_for_two(stack_a);
	if (i == 3)
		case_for_three(stack_a, l_main->next - 1);
	if (i == 4)
		case_for_four(stack_a, stack_b, l_main);
	if (i == 5)
		case_for_five(stack_a, stack_b, 0, l_main);
}
