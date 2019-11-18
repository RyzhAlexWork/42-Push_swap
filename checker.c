
#include "push_swap.h"
#include <stdio.h>

int ft_validcom(char *s, t_list **stack_a, t_list **stack_b)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		ft_push_a(stack_a, stack_b);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		ft_push_b(stack_a, stack_b);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		ft_swap_s(stack_a, stack_b);
	else if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		ft_swap_a(stack_a);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		ft_swap_b(stack_b);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ft_rotate_a(stack_a);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		ft_rotate_a(stack_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		ft_rotate_r(stack_a, stack_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		ft_revrotate_a(stack_a);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		ft_revrotate_b(stack_b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		ft_revrotate_r(stack_a, stack_b);
	else
		return (-1);
	return (1);
}

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

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char 	*line;
	char 	*str;
	int 	i;
	int 	fd;

	i = 0;
	line = NULL;
	stack_a = NULL;
	stack_b = NULL;
	fd = open("ra", O_RDONLY);
	str = ft_strnew(10);
	if (ft_validation(argc, argv, &stack_a) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	while (stack_a->prev != NULL)
		stack_a = stack_a->prev;
	while (get_next_line(0, &line))
	{
		str = ft_strjoinfree(str, line);
		str = ft_strjoinfree(str, "\n");
	}
	while (str[i] != '\0')
	{
		if (ft_validcom(str + i, &stack_a, &stack_b) == -1)
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		else
		{
			while (str[i] != '\0' && str[i] != '\n')
				i++;
			if (str[i] == '\n')
				i++;
		}
	}
	lastcheck(stack_a, stack_b);
	if (stack_b != NULL)
		ft_clear_list(&stack_b);
	ft_clear_list(&stack_a);
	free(line);
	return (0);
}
