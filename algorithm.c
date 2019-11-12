#include "push_swap.h"
#include <stdio.h>

void	ft_algorithm4(t_list **stack_a, t_list **stack_b, t_main *l_main)
{
	int i;

	i = (*stack_a)->flag;
	while ((*stack_a)->flag == i && (*stack_a)->order >= l_main->next)
	{
		if ((*stack_a)->order > l_main->mid)
			l_main->mid = (*stack_a)->order;
		ft_push_b(stack_a, stack_b);
	}
}

void	ft_algorithm3(t_list **stack_a, t_list **stack_b, t_main *l_main)
{
	int i;

	i = 0;
	while (*(stack_b) != NULL)
	{
		if ((*stack_b)->order == l_main->next)
		{
			ft_push_a(stack_a, stack_b);
			ft_rotate_a(stack_a);
			l_main->next++;
		}
		else if ((*stack_b)->order >= l_main->mid)
		{
			(*stack_b)->flag = l_main->flag;
			ft_push_a(stack_a, stack_b);
		}
		else
			ft_rotate_b(stack_b);
		i++;
	}
}

void	ft_algorithm2(t_list **stack_a, t_list **stack_b, t_main *l_main)
{
	while ((*stack_b) != NULL)
	{
		l_main->max = l_main->mid;
		l_main->mid = (l_main->max - l_main->next) / 2 + l_main->next;
		l_main->flag++;
		ft_algorithm3(stack_a, stack_b, l_main);
	}
}

void	ft_algorithm(t_list *stack_a, int i)
{
	t_list	*stack_b;
	t_main	*l_main;
	int 	j;
	int 	k;

	j = 0;
	stack_b = NULL;
	l_main = ft_crmain(i);
	k = l_main->max;
	while (j < l_main->max)
	{
		if (stack_a->order <= l_main->mid)
			ft_push_b(&stack_a, &stack_b);
		else
			ft_rotate_a(&stack_a);
		j++;
	}
	while (l_main->next < k || stack_b != NULL)
	{
		ft_algorithm2(&stack_a, &stack_b, l_main);
		ft_algorithm4(&stack_a, &stack_b, l_main);
	}
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("\n");
	while (stack_b != NULL)
	{
		printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
}
