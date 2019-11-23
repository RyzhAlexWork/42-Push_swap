/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:27:29 by jbowen            #+#    #+#             */
/*   Updated: 2019/11/24 00:27:32 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	while ((*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp->prev = (*stack_a);
	tmp->next = NULL;
	while ((*stack_a)->prev != NULL)
		(*stack_a) = (*stack_a)->prev;
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	while ((*stack_b)->next != NULL)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = tmp;
	tmp->prev = (*stack_b);
	tmp->next = NULL;
	while ((*stack_b)->prev != NULL)
		(*stack_b) = (*stack_b)->prev;
}

void	ft_rotate_r(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
}

void	ft_revrotate_a(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	while ((*stack_a)->next != NULL)
		(*stack_a) = (*stack_a)->next;
	((*stack_a)->prev)->next = NULL;
	tmp = (*stack_a);
	while ((*stack_a)->prev != NULL)
		(*stack_a) = (*stack_a)->prev;
	(*stack_a)->prev = tmp;
	tmp->next = (*stack_a);
	tmp->prev = NULL;
	(*stack_a) = (*stack_a)->prev;
}

void	ft_revrotate_b(t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	while ((*stack_b)->next != NULL)
		(*stack_b) = (*stack_b)->next;
	((*stack_b)->prev)->next = NULL;
	tmp = (*stack_b);
	while ((*stack_b)->prev != NULL)
		(*stack_b) = (*stack_b)->prev;
	(*stack_b)->prev = tmp;
	tmp->next = (*stack_b);
	tmp->prev = NULL;
	(*stack_b) = (*stack_b)->prev;
}
