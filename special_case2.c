#include "push_swap.h"

void	case_for_five(t_list **stack_a, t_list **stack_b, int i)
{
	while (i < 2)
	{
		if ((*stack_a)->order < 3)
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
	case_for_three(stack_a, 2);
	ft_push_a(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
	write(1, "pa\npa\n", 6);
	if ((*stack_a)->order == 2)
	{
		ft_swap_a(stack_a);
		write(1, "sa\n", 3);
	}
}
