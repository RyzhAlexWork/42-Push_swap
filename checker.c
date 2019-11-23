/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbowen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:26:55 by jbowen            #+#    #+#             */
/*   Updated: 2019/11/24 00:26:58 by jbowen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_validcom(char *s, t_list **stack_a, t_list **stack_b)
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

int		ft_checkpovt(t_list *s_a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int 	i;

	while (s_a->prev != NULL)
		s_a = s_a->prev;
	tmp1 = s_a;
	while (s_a != NULL)
	{
		i = 0;
		tmp2 = tmp1;
		while (tmp2 != NULL)
		{
			if (s_a->value == tmp2->value)
				i++;
			if (i > 1)
				return (-1);
			tmp2 = tmp2->next;
		}
		s_a = s_a->next;
	}
	return (1);
}

void	ft_support2(char *str, t_list *stack_a, t_list *stack_b)
{
	int i;

	i = 0;
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
}

void	ft_support(char *line, char *str, t_list *stack_a, t_list *stack_b)
{
	while (get_next_line(0, &line))
	{
		str = ft_strjoinfree(str, line);
		str = ft_strjoinfree(str, "\n");
	}
	ft_support2(str, stack_a, stack_b);
	if (ft_checkpovt(stack_a) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}

int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char 	*line;
	char 	*str;

	line = NULL;
	stack_a = NULL;
	stack_b = NULL;
	str = ft_strnew(10);
	if (ft_validation(argc, argv, &stack_a) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	while (stack_a->prev != NULL)
		stack_a = stack_a->prev;
	ft_support(line, str, stack_a, stack_b);
	lastcheck(stack_a, stack_b);
	if (stack_b != NULL)
		ft_clear_list(&stack_b);
	ft_clear_list(&stack_a);
	free(line);
	return (0);
}
