#include "push_swap.h"
#include <stdio.h>

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
	if (ft_validation(argc, argv, &l_num) == -1 ||
	(array = ft_makearray(l_num, &i)) == NULL)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	printf("%d\n", array[0]);
	printf("%d\n", array[1]);
	printf("%d\n", array[2]);
	printf("%d\n", array[3]);
	printf("%d\n", array[4]);
	printf("%d\n", array[5]);
	free(array);
	ft_clear_list(&l_num);
	return (0);
}