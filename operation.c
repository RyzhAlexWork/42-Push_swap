#include "push_swap.h"

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b) == NULL)
		return ;
	if ((*stack_a) == NULL)
	{
		(*stack_a) = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = NULL;
	}
	else
	{
		(*stack_a)->prev = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		if (*stack_b != NULL)
			(*stack_b)->prev = NULL;
		((*stack_a)->prev)->next = (*stack_a);
		(*stack_a) = (*stack_a)->prev;
	}
}

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a) == NULL)
		return ;
	if ((*stack_b) == NULL)
	{
		(*stack_b) = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
	}
	else
	{
		(*stack_b)->prev = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		if (*stack_a != NULL)
			(*stack_a)->prev = NULL;
		((*stack_b)->prev)->next = (*stack_b);
		(*stack_b) = (*stack_b)->prev;
	}
}

void	ft_swap_a(t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	(*stack_a)->prev = tmp;
	if (tmp->next != NULL)
		(tmp->next)->prev = (*stack_a);
	tmp->next = (*stack_a);
	tmp->prev = NULL;
	(*stack_a) = (*stack_a)->prev;
}

void	ft_swap_b(t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	(*stack_b)->prev = tmp;
	if (tmp->next != NULL)
		(tmp->next)->prev = (*stack_b);
	tmp->next = (*stack_b);
	tmp->prev = NULL;
	(*stack_b) = (*stack_b)->prev;
}

void	ft_swap_s(t_list **stack_a, t_list **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
}
