#include "push_swap.h"
#include <stdio.h>

int		ft_algorithm5(t_list **stack_a, t_list **stack_b, t_main *l_main)
{
	int i;
	int	j;
	int k;

	j = 0;
	i = 0;
	while ((*stack_a)->order == l_main->next)
	{
		ft_rotate_a(stack_a);
		write(1, "ra\n", 3);
		l_main->next++;
		j++;
	}
	k = j;
	while (j < l_main->max)
	{
		if ((*stack_a)->order <= l_main->mid)
		{
			ft_push_b(stack_a, stack_b);
			write(1, "pb\n", 3);
			i++;
		}
		else
		{
			ft_rotate_a(stack_a);
			write(1, "ra\n", 3);
		}
		j++;
	}
	while (k > 0)
	{
		ft_rotate_a(stack_a);
		write(1, "ra\n", 3);
		k--;
	}
	return (i);
}

int		ft_algorithm4(t_list **stack_a, t_list **stack_b, t_main *l_main)
{
	int i;
	int j;

	i = (*stack_a)->flag;
	j = 0;
	while ((*stack_a)->flag == i && (*stack_a)->order >= l_main->next)
	{
		if ((*stack_a)->order == l_main->next)
		{
			ft_rotate_a(stack_a);
			write(1, "ra\n", 3);
			l_main->next++;
		}
		else
		{
			if ((*stack_a)->order > l_main->mid)
				l_main->mid = (*stack_a)->order;
			ft_push_b(stack_a, stack_b);
			write(1, "pb\n", 3);
			j++;
		}
	}
	return (j);
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
			write(1, "pa\nra\n", 6);
			l_main->next++;
		}
		else if ((*stack_b)->order >= l_main->mid)
		{
			(*stack_b)->flag = l_main->flag;
			ft_push_a(stack_a, stack_b);
			write(1, "pa\n", 3);
		}
		else
		{
			ft_rotate_b(stack_b);
			write(1, "rb\n", 3);
		}
		i++;
	}
}

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

void	ft_algorithm2(t_list **stack_a, t_list **stack_b, t_main *l_main, int i)
{
	if (i > 1 && ft_check(stack_b, i) == 1)
	{
		ft_push_rot(stack_a, stack_b, i);
		l_main->next = l_main->next + i;
	}
	else if (i > 1 && i < 6)
	{
		special_case(stack_b, stack_a, i);
		ft_push_rot(stack_a, stack_b, i);
		l_main->next = l_main->next + i;
	}
	while ((i > 5 || i == 1) && (*stack_b) != NULL)
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
	int 	k;

	stack_b = NULL;
	l_main = ft_crmain(i);
	k = l_main->max;
	if (i <= 5)
		special_case(&stack_a, &stack_b, i);
	else
	{
		i = ft_algorithm5(&stack_a, &stack_b, l_main);
		while (l_main->next < k || stack_b != NULL)
		{
			ft_algorithm2(&stack_a, &stack_b, l_main, i);
			i = ft_algorithm4(&stack_a, &stack_b, l_main);
		}
	}
	free(l_main);
}
