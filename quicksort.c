/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:28:29 by jbowen            #+#    #+#             */
/*   Updated: 2019/11/24 00:28:32 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_check(t_list **stack_b, int i)
{
	t_list	*tmp;
	int 	j;

	j = 0;
	tmp = (*stack_b)->next;
	while (tmp != NULL && (*stack_b)->order + 1 == tmp->order)
	{
		(*stack_b) = tmp;
		tmp = tmp->next;
		j++;
	}
	while ((*stack_b)->prev != NULL)
		(*stack_b) = (*stack_b)->prev;
	if (i == j + 1)
		return (1);
	else
		return (-1);
}

void	ft_push_rot(t_list **stack_a, t_list **stack_b, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_push_a(stack_a, stack_b);
		ft_rotate_a(stack_a);
		j++;
		write(1, "pa\nra\n", 6);
	}
}

int		ft_checksort(t_list *l_num)
{
	while (l_num->prev != NULL && (l_num->value > (l_num->prev)->value))
		l_num = l_num->prev;
	if (l_num->prev == NULL)
		exit (0);
	else
		return (1);
}

void	quicksort2(int *array, int *left, int *right, int pivot)
{
	while (*left < *right)
	{
		while ((array[*right] >= pivot) && (*left < *right))
			(*right)--;
		if (*left != *right)
		{
			array[*left] = array[*right];
			(*left)++;
		}
		while ((array[*left] <= pivot) && (*left < *right))
			(*left)++;
		if (*left != *right)
		{
			array[*right] = array[*left];
			(*right)--;
		}
	}
}

void	quicksort(int *array, int left, int right)
{
	int	pivot;
	int	l_hold;
	int	r_hold;

	l_hold = left;
	r_hold = right;
	pivot = array[left];
	quicksort2(array, &left, &right, pivot);
	array[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quicksort(array, left, pivot - 1);
	if (right > pivot)
		quicksort(array, pivot + 1, right);
}
