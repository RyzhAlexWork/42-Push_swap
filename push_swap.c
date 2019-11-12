#include "push_swap.h"
#include <stdio.h>

t_main	*ft_crmain(int i)
{
	t_main	*l_main;

	if ((l_main = malloc(sizeof(t_main))) == NULL)
		exit (-1);
	l_main->next = 1;
	l_main->flag = 1;
	l_main->max = i;
	l_main->mid = l_main->max / 2 + l_main->next;
	return (l_main);
}

void	ft_order(t_list *l_num, int i, int *array)
{
	int j;

	j = 0;
	while (l_num != NULL)
	{
		while (l_num->value != array[j] && j < i)
			j++;
		l_num->order = j + 1;
		j = 0;
		l_num = l_num->prev;
	}
}

int *ft_makearray(t_list *l_num, int *i)
{
	int	j;
	int *array;

	j = 0;
	while (l_num->prev != NULL)
	{
		l_num = l_num->prev;
		(*i)++;
	}
	if ((array = (int *)malloc(sizeof(int) * (*i))) == NULL)
		return (NULL);
	while (j < (*i))
	{
		array[j] = l_num->value;
		j++;
		l_num = l_num->next;
	}
	quicksort(array, 0, *i - 1);
	if ((array = ft_checkrep(array, *i)) == NULL)
		return (NULL);
	return (array);
}

int main(int argc, char **argv)
{
	t_list	*l_num;
	int 	i;
	int 	*array;

	l_num = NULL;
	i = 1;
	if (ft_validation(argc, argv, &l_num) == -1 || ft_checksort(l_num) == -1 ||
	(array = ft_makearray(l_num, &i)) == NULL)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	ft_order(l_num, i, array);
	while (l_num->prev != NULL)
	{
		l_num = l_num->prev;
	}
	ft_algorithm(l_num, i);
	free(array);
	ft_clear_list(&l_num);
	return (0);
}